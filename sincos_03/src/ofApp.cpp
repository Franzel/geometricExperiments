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
    gui.add(thickness.set("THICKNESS",1.0,0.01,5.00));
    gui.add(nDivisions.set("N_DIVISIONS",44,1,87));
    gui.loadFromFile("settings.xml");

    ///---- INITIALIZE
    ofSetCircleResolution(60);
    ofSetBackgroundColor(0);
    res.set(ofGetWindowWidth(), ofGetWindowHeight());
    origin.set(res/2);
    radius = 100;
    rad = 2;
    nDivisions = 10; //must delete this after gui param is implemented
    float gap = 100;
    
    for(int i=0;i<nDivisions;i++){
        for(int j=0;j<nDivisions;j++){
            float tempAngle = (TWO_PI / nElements) * i;
            float x = i*gap;
            float y = j*gap;
            ofVec2f temp;
            temp.set(x,y);
            positions.push_back(temp);
        }
    }
}

//-------------------------------------------------------------
void ofApp::update(){
    for(int i=0;i<nDivisions;i++){
        for(int j=0;j<nDivisions;j++){
            float tempAngle = (TWO_PI / positions.size()) * i;
//            positions[i].x = i*gap + cos(tempAngle) * (radX + ampParam * sin(freqParam *ofGetElapsedTimef()+i)) ;
//            positions[i].y = j*gap + sin(tempAngle) * (radY + ampParam * sin(freqParam *ofGetElapsedTimef()+i));
            positions[i].x = i*gap;
            positions[i].y = j*gap;
        
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::black, ofColor(0,40,50), OF_GRADIENT_CIRCULAR);
    ofSetWindowTitle(ofToString(ofGetFrameRate()));

    ///RINGS

    for(int j=0;j<15;j++){
        ofColor c;
        c.setHsb((10*j), 255, 255);
        ofSetColor(c);
        for(int i=0;i<positions.size();i++){
            ofVec2f diff = positions[i]-ofVec2f(mouseX,mouseY) ;
            diff.normalize();
//            ofVec2f r = positions[i] + diff*j*gap*(gap+sin(ofGetElapsedTimef()*0.35)*(radX*0.01));
            
            
            float cycle = sin(ofGetElapsedTimef()*freqParam);
            
            ofVec2f r = positions[i] + diff*j*(cycle+1)/2*gap;
            ofDrawCircle(r, 10-j);
            ofDrawLine(r, r + diff.getRotated(cycle) * (2*ampParam*j));
        }

        ofVec2f currRadius = positions[0] - origin;
        currRadius.normalize();

    }

//    ///DOTS
//    ofSetLineWidth(1.0);
//    for(int i=0;i<positions.size();i++){
//        ofDrawCircle(positions[i].x, positions[i].y, rad);
//    }
    
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
    
    ///GUI
    gui.draw();

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
