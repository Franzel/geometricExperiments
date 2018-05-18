#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    
    ///---- GUI
    gui.setup();
    gui.add(maxRadX.set("RAD_X", 300.0, 0.0, 900));
    gui.add(maxRadY.set("RAD_Y", 300.0, 0.0, 900.0));
    gui.add(freq.set("FREQ",0.8,-2.00,2.00));
    gui.add(amp.set("AMP",10.0,-60.0,60.0));
    gui.add(speed.set("WAVE_SPEED",2.5,-5.0,5.0));
    gui.add(nRings.set("nRINGS",36,1,64));
    gui.add(nElements.set("nELEMENTS",180,2,400));
    //gui.loadFromFile("settings.xml");
    //gui.setTextColor(ofColor(255));
    
    ///---- INITIALIZE
    center.set(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    center.set(0,0);
    
    ofBackground(20);
    ofSetCircleResolution(100);
    light.setPointLight();
    
    
    for(int i=0; i<60;i++){
        Creature tempCreature(ofRandom(3,30), 24, ofRandom(40,150), ofRandom(40,150), ofRandom(1,2.5), ofRandom(5,60), ofRandom(-2,2));
        tempCreature.setup();
        tempCreature.center.set(ofRandom(-1500,1500), ofRandom(-1500,1500), ofRandom(-1500,1500));
        creatures.push_back(tempCreature);
        
    }
}

//--------------------------------------------------------------
void ofApp::update(){

    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofEnableDepthTest();
    
    cam.begin();
//    float time = ofGetElapsedTimef();
//    
//    for (int i=0; i<nRings ; i++){
//        float angle = HALF_PI + PI/nRings * i;
//        
//        //Set position in X and Y
//        float x = center.x + cos(angle) * maxRadX;
//        float y = center.y + sin(angle) * maxRadY + sin(i*0.5+time)*10;
//        
//        float ringRadius = ofDist(center.x, center.y+y, x, center.y+y);
//        
//        //        //testing perpendicular radius calculation
//        //        ofDrawCircle(x, y, 5);
//        //        ofDrawLine(x, y, x+ringRadius*2, y);
//        
//        ringRadius += (sin(speed*time+i * freq)+1)/2 * amp;
//        
//        //Draw perpendicular circles
//        ofPushMatrix();
//        ofTranslate(center.x, y);
//        ofRotateX(90);
//
//        ofNoFill();
//        ofSetLineWidth(1);
//        ofFill();
//        ofColor c;
//        c.setHsb(127+127*sin(speed*time + i*freq), 200+55*sin(speed*time + i*freq/2), 200+55*sin(i * 0.5 +time),100);
//        ofSetColor(c);
//        ofDrawCircle(0,0, ringRadius);
//        ofPopMatrix();
//        
//        
//        //Draw thorns
//        for (int j=0; j<nElements ; j++){
//            float angle2 = TWO_PI/nElements*j;
//            float x2 = center.z + cos(angle2) * ringRadius + sin(speed*time)*5 ;
//            float z  = center.z + sin(angle2) * ringRadius ;
//            ofVec3f pos;
//            pos.set(x2,y,z);
//            c.setHsb(127+127*sin(i * 0.1 +time), 255, 127+127*sin(i * 0.5 +time));
//            ofSetColor(c);
//            ofDrawSphere(pos, 1 + sin(speed*time+i * freq*4)*0.5);
//            ofVec3f diff = pos-center;
//            diff.normalize();
//            ofDrawLine( pos+diff* (15+sin(speed*time + i*freq)*15), pos+diff* (8+sin(speed*time + i*freq+FOUR_PI)*8));
//        }
//    }

    
    for(int i=0; i<creatures.size();i++){
        creatures[i].draw();
    }
    
    ///CAM
    cam.end();
    ofDisableDepthTest();
    
    ///CAPTURE
    if (bSnapshot == true){
        // grab a rectangle at 200,200, width and height of 300,180
        img.grabScreen(0,0, ofGetScreenWidth(), ofGetScreenHeight());
        
        string fileName = "snapshot_"+ofToString(10000+snapCounter)+".png";
        img.save(fileName, OF_IMAGE_QUALITY_BEST);
        snapString = "saved " + fileName;
        snapCounter++;
        bSnapshot = false;
    }
    ///GUI
    gui.draw();
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 's':
            bSave=true;
            break;
        case 'm':
            bSnapshot=!bSnapshot;
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
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
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
