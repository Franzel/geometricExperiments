#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    res.set(ofGetWindowWidth(), ofGetWindowHeight());
    origin.set(res/2);
    radius = 300;
    nElements = 90;
    rad = 2;
    
    for(int i=0;i<nElements;i++){
        float tempAngle = (TWO_PI / nElements) * i;
        float x = origin.x + cos(tempAngle) * radius;
        float y = origin.y + sin(tempAngle) * radius;
        ofVec2f temp;
        temp.set(x,y);
        positions.push_back(temp);
    }
    
    ofEnableSmoothing();
    
    
    
}

//-------------------------------------------------------------
void ofApp::update(){
    for(int i=0;i<positions.size();i++){
        int id;
        if(i>nElements/2){
            id = nElements-i;
        }else{
            id=i;
        }
        float tempAngle = (TWO_PI / nElements) * i;
        positions[i].x = origin.x + cos(tempAngle) * (200 + 5 * sin(2 *ofGetElapsedTimef()+id)) ;
        positions[i].y = origin.y + sin(tempAngle) * (200 + 5 * sin(2 *ofGetElapsedTimef()+id));
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofNoFill();
    
    for(int j=0;j<10;j++){
        ofSetLineWidth(j/2);
        ofBeginShape();
        for(int i=0;i<positions.size();i++){
            ofDrawCircle(positions[i].x, positions[i].y, rad);
            ofVec2f diff = positions[i]-origin ;
            diff.normalize();
            
            ofVec2f r = positions[i] + diff*j*10;
            ofVertex(r.x, r.y);
        }
        ofEndShape();
    }
    
    
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
