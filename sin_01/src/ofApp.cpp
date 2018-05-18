#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    scr.set(ofGetScreenWidth(), ofGetScreenHeight());
    ofSetWindowShape(scr.x, scr.y);
    ofSetFullscreen(true);
    scrCenter.set(scr/2);
    
    ofSetBackgroundColor(255, 240, 230);
    
    ///Circle
    ofSetCircleResolution(100);
    circleOrigin.set(scrCenter);
    circleRadius = scr.y/3;
    angle=0;

}

//--------------------------------------------------------------
void ofApp::update(){
    angle = ofMap(mouseY, 0, scr.y, 0, TWO_PI);

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0);
    ofNoFill();
    ofSetLineWidth(3);
    ofDrawCircle(circleOrigin, circleRadius);
    
    ofFill();
    ofDrawCircle(circleOrigin, circleRadius/64);
    
    float x = circleOrigin.x + cos(angle) * circleRadius;
    float y = circleOrigin.y + sin(angle) * circleRadius;
    ofVec2f angPos;
    angPos.set(x,y);
    
    ofDrawLine(circleOrigin, angPos );


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
