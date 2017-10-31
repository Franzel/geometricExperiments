#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ///---- GUI
    gui.setup();
    gui.add(radX.set("SINE", 200.0, 0.0, 900));
    gui.add(radY.set("COSINE", 200.0, 0.0, 900.0));
    gui.add(freqParam.set("FREQ",2.0,-30.0,30.0));
    gui.add(ampParam.set("AMP",2.0,-30.0,30.0));

    ///---- INITIALIZE
    ofSetCircleResolution(100);
    ofSetBackgroundColor(0);
    res.set(ofGetWindowWidth(), ofGetWindowHeight());
    origin.set(res/2);
    radius = 300;
    nElements = 30;
    rad = 2;
   
    for(int i=0;i<nElements;i++){
        float tempAngle = (TWO_PI / nElements) * i;
        float x = origin.x + cos(tempAngle) * radius;
        float y = origin.y + sin(tempAngle) * radius;
        ofVec2f temp;
        temp.set(x,y);
        positions.push_back(temp);
    }
}

//-------------------------------------------------------------
void ofApp::update(){
    
    
    for(int i=0;i<positions.size();i++){
        int id;
        if(i>positions.size()/2){
            id = positions.size()-i;
        }else{
            id=i;
        }
        float tempAngle = (TWO_PI / positions.size()) * i;
        positions[i].x = origin.x + cos(tempAngle) * (radX + ampParam * sin(freqParam *ofGetElapsedTimef()+id)) ;
        positions[i].y = origin.y + sin(tempAngle) * (radY + ampParam * sin(freqParam *ofGetElapsedTimef()+id));
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    gui.draw();
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
    if(key==OF_KEY_UP){
        ofVec2f temp;
        positions.push_back(temp);
    }
    
    if(key==OF_KEY_DOWN){
        positions.erase(positions.begin());
        cout<<positions.size()<<endl;
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
