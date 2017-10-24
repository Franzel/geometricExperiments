// Francisco Zamorano
// October 2017

#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0, 0, 0);
    origin.set(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    ofSetCircleResolution(60);
    
    size = 5.5;
    nElements = 1280;
    bSave = false;
    ofSetVerticalSync(true);
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    angle = ofGetElapsedTimef() * 1.0;
    radius = 300;
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    if( bSave ){
        ofBeginSaveScreenAsPDF("screenshot-"+ofGetTimestampString()+".pdf", false);
    }
    
    float phase  = ofMap(mouseX, 0, ofGetWindowWidth(), 0, 1);
    float phaseY  = ofMap(mouseY, 0, ofGetWindowHeight(), 0, 1);
    ofColor b;
    b.setHsb(255, 255, 60);
    ofBackgroundGradient(ofColor(0,0,0), b, OF_GRADIENT_CIRCULAR);
    
    ofSetColor(255);
    for(int h=0; h<1;h++){
        for(int i=0; i<nElements;i++){
            float id;
            if(i>nElements/2){
                id = nElements-i;
            }else{
                id=i;
            }
            
            
            
            
            float x = origin.x + cos(TWO_PI/nElements*i) * ((h*10)+ radius * (cos(angle+id*phase)+1)/2);
            float y = origin.y + sin(TWO_PI/nElements*i) * ((h*10)+ radius * (sin(angle+id*phase)+1)/2);
            
            float osc = (cos(id*phase)+1)/2;
            c.setHsb(80 + osc*55 , 200 + osc*100, 130+125*osc);

//            ofDrawRectangle(x,y, size * osc, size * osc);
            ofSetLineWidth(0.2);
            ofSetColor(c * 0.7,100);
            if(i%6==0) ofDrawLine(x,y, origin.x, origin.y);
            
            ofSetColor(c);
            ofDrawCircle(x,y,size * osc);
            
        }
    }
    
    if( bSave ){
        ofEndSaveScreenAsPDF();
        bSave = false;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 's':
            bSave=true;
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
