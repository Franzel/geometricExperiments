#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ///---- GUI
    gui.setup();
    gui.add(radX.set("RAD_X", 200.0, 0.0, 900));
    gui.add(radY.set("RAD_Y", 200.0, 0.0, 900.0));
    gui.add(freqParam.set("FREQ",2.00,-20.00,20.00));
    gui.add(ampParam.set("AMP",2.0,-30.0,30.0));
    gui.add(nRings.set("N_RINGS",30,1,60));
    gui.add(gap.set("GAP",10,-10,60));

    ///---- INITIALIZE
    ofSetCircleResolution(60);
    ofSetBackgroundColor(0);
    res.set(ofGetWindowWidth(), ofGetWindowHeight());
    origin.set(res/2);
    radius = 100;
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
        int id = i;
//        if(i>positions.size()/2){
//            id = positions.size()-i;
//        }else{
//            id=i;
//        }
        float tempAngle = (TWO_PI / positions.size()) * i;
        positions[i].x = origin.x + cos(tempAngle) * (radX + ampParam * sin(freqParam *ofGetElapsedTimef()+id)) ;
        positions[i].y = origin.y + sin(tempAngle) * (radY + ampParam * sin(freqParam *ofGetElapsedTimef()+id));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::darkCyan, ofColor::black, OF_GRADIENT_CIRCULAR);
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    gui.draw();
    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofNoFill();
    
    ///RINGS
    for(int j=0;j<nRings;j++){
        ofSetLineWidth(j*0.2);
        ofColor c;
        c.setHsb(j*2*gap, 255, 255);
        ofSetColor(c);
        
        ofBeginShape();

        for(int i=0;i<positions.size();i++){
            ofVec2f diff = positions[i]-origin ;
            diff.normalize();
            ofVec2f r = positions[i] + diff*j*gap;
            ofVertex(r.x, r.y);
        }
        ofEndShape();
    }
    
    ///DOTS
    ofSetLineWidth(1);
    for(int i=0;i<positions.size();i++){
        ofDrawCircle(positions[i].x, positions[i].y, rad);
    }
    
    ///CAPTURE
    if (bSnapshot == true){
        // grab a rectangle at 200,200, width and height of 300,180
        img.grabScreen(0,0, res.x, res.y);
        
        string fileName = "snapshot_"+ofToString(10000+snapCounter)+".png";
        img.save(fileName, OF_IMAGE_QUALITY_BEST);
        snapString = "saved " + fileName;
        snapCounter++;
        bSnapshot = false;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key==OF_KEY_UP){
        ofVec2f temp;
        positions.push_back(temp);
        cout<<positions.size()<<endl;
    }
    
    if(key==OF_KEY_DOWN){
        positions.erase(positions.begin());
        cout<<positions.size()<<endl;
    }
    
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
