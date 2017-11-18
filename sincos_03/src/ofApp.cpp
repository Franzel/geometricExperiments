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
    gui.add(waveSpeed.set("WAVE_SPEED",1.0,-5.0,5.0));
    gui.add(gap.set("GAP",30,-10,400));
    gui.add(thickness.set("THICKNESS",5,0.0,55.00));
    gui.add(nDivisions.set("N_DIVISIONS",44,1,87));
    gui.loadFromFile("settings.xml");
    
    ///---- INITIALIZE
    
    ofSetCircleResolution(60);
    ofSetBackgroundColor(0);
    res.set(ofGetWindowWidth(), ofGetWindowHeight());
    origin.set(0,0);
    radius = 100;
    rad = 2;
    nRows = 24; //must delete this after gui param is implemented
    nCols = 24; //must delete this after gui param is implemented
    
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
    
    bMouse = true;
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
    
    if(bMouse){
        center.set(mouseX,mouseY);
    }else{
        center.x = ofGetWindowWidth()/2;
        center.y = ofGetWindowHeight()/2;
    }
    //    center.x = ofGetWindowWidth()/2 + cos(ofGetElapsedTimef()*freqParam) * radX;
    //    center.y = ofGetWindowHeight()/2 + sin(ofGetElapsedTimef()*freqParam) * radY;
    
    
    
    for (int i=0;i<nIter;i++){
        for (int j=0;j<positions.size();j++){
            ofVec2f diff = positions[j]-center;//ofVec2f(mouseX,mouseY) ;
            diff.normalize();
            
            float distToCenter = positions[j].distance(center);
//            ofVec3f r = positions[j] + diff*j* ((sin(ofGetElapsedTimef()+distToCenter)+1/2)*diff*ampParam)/gap;
            ofVec3f r = positions[j];
            r.z += sin(freqParam*ofGetElapsedTimef()*waveSpeed+distToCenter/50)*ampParam*20;
            
            ofColor c;
            c.setHsb(i*(distToCenter*cycle)/nIter, 255, 600-distToCenter);
            ofSetColor(c);
            ofDrawCircle(r + (ampParam*cycle)*diff*i, thickness-i*thickness/nIter);
            
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
        case 'l':
            bMouse=!bMouse;
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
