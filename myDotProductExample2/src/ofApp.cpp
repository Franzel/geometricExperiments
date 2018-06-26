#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(0);
    ofEnableAlphaBlending();
    ofSetCircleResolution(100);
    bAutoRay = false;

    
    center.set(ofGetWidth()/2, ofGetHeight()/2);
    
    baseLength = 100;
    baseOrigin.set(center.x-baseLength,center.y);
    baseEnd.set(center.x+baseLength,center.y);
    
    rayOrigin.set(center.x, center.y - ofGetHeight()/2 + 100);
    
    distToZeroX = ofDist(rayOrigin.x, rayOrigin.y, 0, rayOrigin.y);
    distToZeroY = ofDist(rayOrigin.x, rayOrigin.y, rayOrigin.x, 0);
    
    
    if(bMoveOrigin){
        baseOrigin.set(mouseX, mouseY);
    }
    
    if(bMoveEnd){
        baseEnd.set(mouseX, mouseY);
    }
    
    
    ///Multilines
    for (int i=0;i<100;i++) {
        line temp;
        temp.length = 30;
        temp.begin.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        //        temp.end.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        
        int directionX = round(ofRandom(-1,1));
        int directionY = round(ofRandom(-1,1));
        temp.end.set(temp.begin.x + temp.length * directionX, temp.begin.y + temp.length * directionY);
        
        temp.dir = temp.end - temp.begin;
        temp.dir.normalize();
        temp.end.set(temp.begin.x + temp.dir.x * temp.length, temp.begin.y + temp.dir.y * temp.length);
        lines.push_back(temp);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    rayVector = rayEnd-rayOrigin;
    rayVector.normalize();
    
    baseVector = baseEnd - baseOrigin;
    baseVector.normalize();
    
    dot = 1 - abs(rayVector.dot(baseVector));
    //cout<<dot<<endl;
    
    for (int i=0;i<lines.size();i++) {
        lines[i].dot = abs(rayVector.dot(lines[i].dir));
        lines[i].thickness = 0.5 + 2*lines[i].dot;
        lines[i].length = 30*lines[i].dot;
        lines[i].ctr = lines[i].begin.getMiddle(lines[i].end);
    }
    
    if(bAutoRay){
        float osc = sin(ofGetElapsedTimef()+2);
        float x = rayOrigin.x + cos(ofGetElapsedTimef()) * (100 * osc);
        float y = rayOrigin.y + sin(ofGetElapsedTimef()) * (100 * osc);
        rayEnd.set(x,y);
    }else{
        rayEnd.set(mouseX , mouseY);
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //    ofDrawEllipse(center,30 *dot,30*dot);
    
    ofSetColor(255,0,0);
    ofSetLineWidth(1);
    ofDrawEllipse(rayOrigin,5,5);
    ofDrawLine(rayOrigin, rayEnd);
    
    //        ofSetLineWidth(10*dot);
    //        ofDrawLine(baseOrigin,baseEnd);
    
    for (int i=0;i<lines.size();i++) {
        float thisDot = lines[i].dot;
        float thisLength = lines[i].length;
        ofSetColor(127 + 127*sin(i * 0.01  *thisDot),
                   127 + 127*sin(i * 0.011 *thisDot),
                   127 + 127*sin(i * 0.012 *thisDot),
                   255*thisDot);
        ofSetLineWidth(lines[i].thickness);
        ofDrawEllipse(lines[i].ctr, 8 * thisDot, 8 * thisDot);
        ofDrawLine(lines[i].ctr + lines[i].dir * thisLength, lines[i].ctr - lines[i].dir * thisLength);
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case '1':
            bMoveOrigin=!bMoveOrigin;
            break;
        case '2':
            bMoveEnd=!bMoveEnd;
            break;
        case 'a':
            bAutoRay=!bAutoRay;
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
