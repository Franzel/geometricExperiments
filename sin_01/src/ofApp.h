#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "scene0101.h"
#include "scene0102.h"
#include "scene0103.h"
#include "scene0104.h"
#include "scene0201.h"
#include "scene0202.h"
#include "scene0203.h"
#include "scene0204.h"

#define NSCENES  8

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
		baseScene  * scenes[NSCENES];
		int currentScene;
	
		
};
