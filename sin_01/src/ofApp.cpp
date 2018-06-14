#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	scenes[0] = new scene0101();
	scenes[1] = new scene0102();
	scenes[2] = new scene0103();
    scenes[3] = new scene0104();
    scenes[4] = new scene0201();
    scenes[5] = new scene0203();
    scenes[6] = new scene0202();
    scenes[7] = new scene0204();
	
	currentScene = 0;
	
	for (int i = 0; i < NSCENES; i++){
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
        currentScene %= NSCENES;
    }

    if(key==OF_KEY_LEFT){
        currentScene--;
        if(currentScene<0){
            currentScene = NSCENES-1;
        };
    }
	((scene0101*)scenes[0])->keyPressed(key);
    ((scene0102*)scenes[1])->keyPressed(key);
    ((scene0103*)scenes[2])->keyPressed(key);
    ((scene0104*)scenes[3])->keyPressed(key);
    ((scene0201*)scenes[4])->keyPressed(key);
    ((scene0202*)scenes[5])->keyPressed(key);
    ((scene0203*)scenes[6])->keyPressed(key);
    ((scene0204*)scenes[7])->keyPressed(key);



	
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
