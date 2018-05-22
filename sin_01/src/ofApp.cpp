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
    
    
    sinColor = ofColor(ofColor::red);
    cosColor = ofColor(ofColor::blue);
    
    sineBar.setup(ofVec2f(circleOrigin + ofVec2f(circleRadius+100,0)), circleRadius,10,-90, sinColor, "SIN");

    cosineBar.setup(ofVec2f(circleOrigin + ofVec2f(0,circleRadius+100)), circleRadius,10,0, cosColor, "COS");

}

//--------------------------------------------------------------
void ofApp::update(){
    angle = ofMap(mouseY, 0, scr.y, 0, TWO_PI);
    cosine = cos(angle);
    sine = sin(angle);
    cosineBar.update(cosine);
    sineBar.update(sine);
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0);
    ofNoFill();
    ofSetLineWidth(3);
    ofDrawCircle(circleOrigin, circleRadius);
    
    ofFill();
    ofDrawCircle(circleOrigin, circleRadius/64);
    
    float x = circleOrigin.x + cosine * circleRadius;
    float y = circleOrigin.y + -sine * circleRadius;
    ofVec2f angPos;
    angPos.set(x,y);
    
    ofDrawLine(circleOrigin, angPos ); //main angle line
    ofSetColor(ofColor::red);
    ofDrawLine(angPos.x,angPos.y, angPos.x, circleOrigin.y);
    
    ofSetColor(ofColor::blue);
    ofDrawLine(circleOrigin.x, circleOrigin.y, angPos.x, circleOrigin.y);
    
    
    
    //bars
    cosineBar.draw();
    sineBar.draw();
    
    
    
    
    
    //numeric info
    ofSetColor(ofColor::black);
    ofDrawBitmapString("angle (deg) = " + ofToString(round(ofRadToDeg(angle))), 100, 100);
    ofDrawBitmapString("angle (rad) = " + ofToString(angle,2), 100, 120);
    ofDrawBitmapString("sin         = " + ofToString(sin(angle),1), 100, 140);
    ofDrawBitmapString("cos         = " + ofToString(cos(angle),1), 100, 160);


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
