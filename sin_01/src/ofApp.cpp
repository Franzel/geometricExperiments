#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	scenes[0] = new scene0101();
	scenes[1] = new scene0102();
	scenes[2] = new scene0101();
	
	currentScene = 0;
	
	for (int i = 0; i < 3; i++){
		scenes[i]->setup();
	}
	
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	scenes[currentScene]->update();
}


//--------------------------------------------------------------
void ofApp::draw(){
	
	scenes[currentScene]->draw();
    ofDrawBitmapString(ofToString(currentScene), 0, 10);
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key==OF_KEY_RIGHT){
	currentScene++;
        currentScene %= 3;
    }

    if(key==OF_KEY_LEFT){
        currentScene--;
        currentScene %= 3;
    }
	((scene0101*)scenes[0])->keyPressed(key);
    ((scene0102*)scenes[1])->keyPressed(key);
    ((scene0101*)scenes[3])->keyPressed(key);

	
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
