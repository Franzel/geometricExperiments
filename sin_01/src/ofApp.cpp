#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
//    ofSetFullscreen(true);
    res.set(ofGetScreenWidth(), ofGetScreenHeight());
    ofSetWindowShape(res.x, res.y);
    ofEnableAlphaBlending();
    ofSetCircleResolution(100);
    
    float rad = 250;
    
    ///SCENES
	scenes[0] = new scene0101();
    scenes[1] = new scene0102();
    scenes[2] = new scene0103();
    scenes[3] = new scene0104();
    scenes[4] = new scene0201();
    scenes[5] = new scene0203();
    scenes[6] = new scene0202();
    scenes[7] = new scene0204();
	
	currentScene = 0;

    for (int i = 0; i < NSCENES; i++){
        scenes[i]->setup(res,rad);
    }
    
    ///ARDUINO
    arduino.setup();
    
    ///INPUTS
    angleInput = 0;
    angle =0;
    angleInputName = "mouse";
    
    lastCycleTime = ofGetElapsedTimef();
    cycleDuration = TWO_PI;
    
    bShowRawinfo = false;


}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(angleInput==0){
        angle = ofMap(ofGetMouseY(), 0, res.y, 0, TWO_PI);//mouse
    }
    else if(angleInput==1){
        
        
        float diffTime = ofGetElapsedTimef() - lastCycleTime;
        if (diffTime > cycleDuration){
            lastCycleTime = ofGetElapsedTimef();
        }
        angle = diffTime;
    }
    else if(angleInput==2){
        arduino.update();
        angle = arduino.rotaryAngle();
    }
    else {
        angle = ofMap(ofGetMouseY(), 0, res.y, 0, TWO_PI);//mouse
    }
    
    cout<<angle<<endl;
    cout<<"input: "<<angleInput<<endl;

	
	scenes[currentScene]->update(angle);
}


//--------------------------------------------------------------
void ofApp::draw(){
	
	scenes[currentScene]->draw();
    ofDrawBitmapString(ofToString(currentScene), 0, 10);
    
    
    //raw numeric info
    if(bShowRawinfo){
        ofSetColor(ofColor::black);
        ofDrawBitmapString("ANGLE (deg) = " + ofToString(ofRadToDeg(angle),4), 100, 100);
        ofDrawBitmapString("angle (rad) = " + ofToString(angle,4), 100, 120);
        ofDrawBitmapString("sin         = " + ofToString(sin(angle),4), 100, 140);
        ofDrawBitmapString("cos         = " + ofToString(cos(angle),4), 100, 160);
        ofDrawBitmapString("Serial      = " + ofToString(arduino.byteData,4), 100, 180);
        ofDrawBitmapString("angle input = " + angleInputName, 100, 200);
    }
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//    if(key==OF_KEY_RIGHT){
//	currentScene++;
//        currentScene %= NSCENES;
//    }
//
//    if(key==OF_KEY_LEFT){
//        currentScene--;
//        if(currentScene<0){
//            currentScene = NSCENES-1;
//        };
//    }
	((scene0101*)scenes[0])->keyPressed(key);
    ((scene0102*)scenes[1])->keyPressed(key);
    ((scene0103*)scenes[2])->keyPressed(key);
    ((scene0104*)scenes[3])->keyPressed(key);
    ((scene0201*)scenes[4])->keyPressed(key);
    ((scene0202*)scenes[5])->keyPressed(key);
    ((scene0203*)scenes[6])->keyPressed(key);
    ((scene0204*)scenes[7])->keyPressed(key);

    switch (key) {
        case '0':
            angleInput = 0;
            angleInputName = "mouse";
            break;
        case '1':
            angleInput = 1;
            angleInputName = "auto";
            break;
        case '2':
            angleInput = 2;
            angleInputName = "rotary";
            break;
        case 'i':
            bShowRawinfo = !bShowRawinfo;
            break;
        case OF_KEY_RIGHT:
            currentScene++;
            currentScene %= NSCENES;
            break;
        case OF_KEY_LEFT:
            currentScene--;
            if(currentScene<0){
                currentScene = NSCENES-1;
            }
            break;
        default:
            break;
    }

	
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
