#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    
    ///---- GUI
    gui.setup();
    gui.add(maxRadX.set("RAD_X", 200.0, 0.0, 900));
    gui.add(maxRadY.set("RAD_Y", 200.0, 0.0, 900.0));
    gui.add(freq.set("FREQ",0.8,-2.00,2.00));
    gui.add(amp.set("AMP",10.0,-30.0,30.0));
    gui.add(speed.set("WAVE_SPEED",2.5,-5.0,5.0));
    gui.add(nRings.set("nRINGS",36,1,64));
    gui.add(nElements.set("nELEMENTS",180,2,400));
    //gui.loadFromFile("settings.xml");
    //gui.setTextColor(ofColor(255));
    
    ///---- INITIALIZE
    center.set(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    center.set(0,0);
    
    ofBackground(20);
    ofSetCircleResolution(100);
    light.setPointLight();
    
    
    
    
    //    maxRadX = 300;
    //    maxRadY = 300;
    //    amp = 10;
    //    freq = 0.8;
    //    speed = 2.5;
    //    nRings = 36;
    //    nElements = 180;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofEnableDepthTest();
    
    cam.begin();
    float time = ofGetElapsedTimef();
    
    for (int i=0; i<nRings ; i++){
        float angle = HALF_PI + PI/nRings * i;
        
        //Set position in X and Y
        float x = center.x + cos(angle) * maxRadX;
        float y = center.y + sin(angle) * maxRadY + sin(i*0.5+time)*10;
        
        float ringRadius = ofDist(center.x, center.y+y, x, center.y+y);
        
        //        //testing perpendicular radius calculation
        //        ofDrawCircle(x, y, 5);
        //        ofDrawLine(x, y, x+ringRadius*2, y);
        
        ringRadius += (sin(speed*time+i * freq)+1)/2 * amp;
        
        //Draw perpendicular circles
        ofPushMatrix();
        ofTranslate(center.x, y);
        ofRotateX(90);
        ofNoFill();
        ofSetLineWidth(1);
        ofFill();
        ofColor c;
        c.set(127+127*sin(speed*time + i*freq), 127+127*sin(speed*time + i*freq/2), 127+127*sin(i * 0.5 +time),100);
        ofSetColor(c);
        ofDrawCircle(0,0, ringRadius);
        ofPopMatrix();
        
        
        //Draw thorns
        for (int j=0; j<nElements ; j++){
            float angle2 = TWO_PI/nElements*j;
            float x2 = center.z + cos(angle2) * ringRadius + sin(speed*time)*5 ;
            float z  = center.z + sin(angle2) * ringRadius ;
            ofVec3f pos;
            pos.set(x2,y,z);
            c.setHsb(127+127*sin(i * 0.1 +time), 255, 127+127*sin(i * 0.5 +time));
            ofSetColor(c);
            ofDrawSphere(pos, 1 + sin(speed*time+i * freq*4)*0.5);
            ofVec3f diff = pos-center;
            diff.normalize();
            ofDrawLine( pos+diff* (15+sin(speed*time + i*freq)*15), pos+diff* (8+sin(speed*time + i*freq+FOUR_PI)*8));
        }
    }
    cam.end();
    ofDisableDepthTest();
    gui.draw();
    
    
    
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
