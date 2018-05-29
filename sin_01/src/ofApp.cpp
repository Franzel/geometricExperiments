#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    scr.set(ofGetScreenWidth(), ofGetScreenHeight());
    ofSetWindowShape(scr.x, scr.y);
    ofSetFullscreen(true);
    scrCenter.set(scr/2);
    
    ofSetBackgroundColor(255, 240, 230);
    
    
    ///colors
    sinColor = ofColor(ofColor::red);
    cosColor = ofColor(ofColor::blue);
    
    ///Circle
    ofSetCircleResolution(100);
    circleOrigin.set(scrCenter.x/3 *1.5, scrCenter.y);
    circleRadius = scr.y/3;
    angle=0;
    
    plane.setup(circleOrigin, scr.y/3, 1.0); //cartesian plane
    mainCircle.setup(circleOrigin, scr.y/3); //circle setup
    
    ///measure Bars
    sineBar.setup(ofVec2f(circleOrigin + ofVec2f(circleRadius+100,0)), circleRadius,10,-90, sinColor, "SIN");
    cosineBar.setup(ofVec2f(circleOrigin + ofVec2f(0,circleRadius+100)), circleRadius,10,0, cosColor, "COS");
    
    
    ///Fonts
    float fontSize = 48;
    ofTrueTypeFont::setGlobalDpi(72);
    fontLight.load("GT-America-Mono-Medium.otf", fontSize, true, true);
    fontLight.setLineHeight(fontSize);
    fontLight.setLetterSpacing(1.0);
    
    
    //OSC
    receiver.setup(PORT);
    current_msg_string = 0;
    cout << "listening for osc messages on port " << PORT << "\n";
    
}

//--------------------------------------------------------------
void ofApp::update(){
    angle = ofMap(mouseY, 0, scr.y, 0, TWO_PI);
    //        angle = ofGetElapsedTimef();
    angle = ofMap(inputAngle,0.0, 1.0, TWO_PI, 0.0f);
    cosine = cos(angle);
    sine = sin(angle);
    cosineBar.update(cosine);
    sineBar.update(sine);
    mainCircle.update(angle);
    
    
    

    ///OSC
    // check for waiting messages
    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(m);
        
        if (m.getAddress() == "/wacom/1/ring/1"){
            inputAngle = m.getArgAsFloat(0);
        }
    }
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    plane.draw();
    mainCircle.draw();
    cosineBar.draw();
    sineBar.draw();
    
    
    //numeric info
    ofSetColor(ofColor::black);
    ofDrawBitmapString("ANGLE (deg) = " + ofToString(ofRadToDeg(angle),4), 100, 100);
    ofDrawBitmapString("angle (rad) = " + ofToString(angle,4), 100, 120);
    ofDrawBitmapString("sin         = " + ofToString(sin(angle),4), 100, 140);
    ofDrawBitmapString("cos         = " + ofToString(cos(angle),4), 100, 160);
    
    
    ///OSC
    string buf;
    buf = "port" + ofToString(PORT);
    ofDrawBitmapString(buf, 100, 20);
    
    // draw state
    buf = "inputAngle: " + ofToString(inputAngle, 4);
    ofDrawBitmapString(buf, 100, 40);
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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
