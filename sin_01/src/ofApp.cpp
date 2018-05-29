#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    scr.set(ofGetScreenWidth(), ofGetScreenHeight());
    ofSetWindowShape(scr.x, scr.y);
    ofSetFullscreen(true);
    scrCenter.set(scr/2);
    
    ofSetBackgroundColor(255, 240, 230);
    

    ///colors
    sinColor = ofColor(ofColor::red);
    cosColor = ofColor(ofColor::blue);
    
    ///Circle
    ofSetCircleResolution(100);
    circleOrigin.set(scrCenter.x/3 *1.5, scrCenter.y);
    circleRadius = scr.y/3;
    angle=0;
    
    plane.setup(circleOrigin, scr.y/3, 1.0); //cartesian plane
    mainCircle.setup(circleOrigin, scr.y/3); //circle setup

    ///measure Bars
    sineBar.setup(ofVec2f(circleOrigin + ofVec2f(circleRadius+100,0)), circleRadius,10,-90, sinColor, "SIN");
    cosineBar.setup(ofVec2f(circleOrigin + ofVec2f(0,circleRadius+100)), circleRadius,10,0, cosColor, "COS");
    
    
    ///Fonts
    float fontSize = 48;
    ofTrueTypeFont::setGlobalDpi(72);
    fontLight.load("GT-America-Mono-Medium.otf", fontSize, true, true);
    fontLight.setLineHeight(fontSize);
    fontLight.setLetterSpacing(1.0);
    
    
    //OSC
    receiver.setup(PORT);
    current_msg_string = 0;
    cout << "listening for osc messages on port " << PORT << "\n";

}

//--------------------------------------------------------------
void ofApp::update(){
    angle = ofMap(mouseY, 0, scr.y, 0, TWO_PI);
//        angle = ofGetElapsedTimef();
    angle = ofMap(inputAngle,0.0, 1.0, TWO_PI, 0.0f);
    cosine = cos(angle);
    sine = sin(angle);
    cosineBar.update(cosine);
    sineBar.update(sine);
    mainCircle.update(angle);
    
    
    
    // hide old messages
    for(int i = 0; i < NUM_MSG_STRINGS; i++){
        if(timers[i] < ofGetElapsedTimef()){
            msg_strings[i] = "";
        }
    }
    
    // check for waiting messages
    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(m);
        
        // check for mouse moved message
        if(m.getAddress() == "/mouse/position"){
            // both the arguments are int32's
            mouseX = m.getArgAsInt32(0);
            mouseY = m.getArgAsInt32(1);
        }
        // check for mouse button message
        else if(m.getAddress() == "/mouse/button"){
            // the single argument is a string
            mouseButtonState = m.getArgAsString(0);
        }
        
        else if (m.getAddress() == "/wacom/1/ring/1"){
            inputAngle = m.getArgAsFloat(0);
        }
        else{
            // unrecognized message: display on the bottom of the screen
            string msg_string;
            msg_string = m.getAddress();
            msg_string += ": ";
            for(int i = 0; i < m.getNumArgs(); i++){
                // get the argument type
                msg_string += m.getArgTypeName(i);
                msg_string += ":";
                // display the argument - make sure we get the right type
                if(m.getArgType(i) == OFXOSC_TYPE_INT32){
                    msg_string += ofToString(m.getArgAsInt32(i));
                }
                else if(m.getArgType(i) == OFXOSC_TYPE_FLOAT){
                    msg_string += ofToString(m.getArgAsFloat(i));
                }
                else if(m.getArgType(i) == OFXOSC_TYPE_STRING){
                    msg_string += m.getArgAsString(i);
                }
                else{
                    msg_string += "unknown";
                }
            }
            // add to the list of strings to display
            msg_strings[current_msg_string] = msg_string;
            timers[current_msg_string] = ofGetElapsedTimef() + 5.0f;
            current_msg_string = (current_msg_string + 1) % NUM_MSG_STRINGS;
            // clear the next line
            msg_strings[current_msg_string] = "";
        }
        
    }

    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    plane.draw();
    mainCircle.draw();
    cosineBar.draw();
    sineBar.draw();
    
   
    //numeric info
    ofSetColor(ofColor::black);
    ofDrawBitmapString("ANGLE (deg) = " + ofToString(ofRadToDeg(angle),4), 100, 100);
    ofDrawBitmapString("angle (rad) = " + ofToString(angle,4), 100, 120);
    ofDrawBitmapString("sin         = " + ofToString(sin(angle),4), 100, 140);
    ofDrawBitmapString("cos         = " + ofToString(cos(angle),4), 100, 160);
    
    
    
    string buf;
    buf = "listening for osc messages on port" + ofToString(PORT);
    ofDrawBitmapString(buf, 10, 20);
    

    
    // draw mouse state
    buf = "inputAngle: " + ofToString(inputAngle, 4);
    ofDrawBitmapString(buf, 430, 20);
    
    for(int i = 0; i < NUM_MSG_STRINGS; i++){
        ofDrawBitmapString(msg_strings[i], 10, 40 + 15 * i);
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
