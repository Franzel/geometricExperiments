#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowPosition(0, 0);
    ///---- GUI
    gui.setup();
    gui.add(radX.set("RAD_X", 200.0, 0.0, 900));
    gui.add(radY.set("RAD_Y", 200.0, 0.0, 900.0));
    gui.add(freqParam.set("FREQ",2.00,-5.00,5.00));
    gui.add(ampParam.set("AMP",2.0,-30.0,30.0));
    gui.add(nRings.set("N_RINGS",30,1,60));
    gui.add(gap.set("GAP",30,-10,100));
    gui.add(thickness.set("THICKNESS",5,0.01,10.00));
    gui.add(nDivisions.set("N_DIVISIONS",44,1,87));
    gui.loadFromFile("settings.xml");

    ///---- INITIALIZE
    
    ofSetCircleResolution(60);
    ofSetBackgroundColor(0);
    res.set(ofGetWindowWidth(), ofGetWindowHeight());
    origin.set(0,0);
    radius = 100;
    rad = 2;
    nRows = 20; //must delete this after gui param is implemented
    nCols = 20; //must delete this after gui param is implemented

//    float gap = 100;
    
    for(int i=0;i<nRows;i++){
        for(int j=0;j<nCols;j++){
            float x = 0;
            float y = 0;
            ofVec2f temp;
            temp.set(x,y);
            positions.push_back(temp);
        }
    }
    cout<<positions.size()<<endl;
}

//-------------------------------------------------------------
void ofApp::update(){
    for(int i=0;i<nRows;i++){
        for(int j=0;j<nCols;j++){
//            float tempAngle = (TWO_PI / positions.size()) * i;
//            positions[i].x = i*gap + cos(tempAngle) * (radX + ampParam * sin(freqParam *ofGetElapsedTimef()+i)) ;
//            positions[i].y = j*gap + sin(tempAngle) * (radY + ampParam * sin(freqParam *ofGetElapsedTimef()+i));
            positions[j*nRows+i].set(origin.x+i*gap, origin.y+j*gap);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor(0), ofColor(0,40,50), OF_GRADIENT_CIRCULAR);
    ofSetWindowTitle(ofToString(ofGetFrameRate()));

   
    float cycle = 1+sin(ofGetElapsedTimef()*freqParam)/2;
    int nIter = nDivisions;
    
    ofVec2f center;
    center.x = ofGetWindowWidth()/2 + cos(ofGetElapsedTimef()*freqParam) * radX;
    center.y = ofGetWindowHeight()/2 + sin(ofGetElapsedTimef()*freqParam) * radY;
//    center.set(mouseX,mouseY);

    
    for (int i=0;i<nIter;i++){
        for (int j=0;j<positions.size();j++){
            ofColor c;
            c.setHsb(i*(240*cycle+0.1)/nIter, 255, 255);
            ofSetColor(c);
            ofVec2f diff = positions[j]-center;//ofVec2f(mouseX,mouseY) ;
            diff.normalize();
            ofVec2f r = positions[j] + diff*j/gap;
//            r.x += cos(ofGetElapsedTimef()+i)  *8;
//            r.y += sin(ofGetElapsedTimef()+i)  *8;

            ofDrawCircle(r + (ampParam*cycle)*diff*i, thickness-i*thickness/nIter);
//            ofDrawLine(r, r + diff.getRotated(0) * (ampParam*cycle)*i);
        }
    }

//    ofDrawCircle(center, 10);
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
            
        case 'p':
            cout<<"gap:"<<gap<<endl;
            for (int i=0;i<positions.size();i++){
                cout<< i << " : " << positions[i]<<endl ;
            }
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
