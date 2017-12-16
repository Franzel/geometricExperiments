#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofVec3f center;
    ofEasyCam   cam;
    ofLight light;
    
    
    ofxPanel gui;
    ofParameter<float> maxRadX;
    ofParameter<float> maxRadY;
    ofParameter<float> freq;
    ofParameter<float> amp;
    ofParameter<float> speed;
    
    ofParameter<int> nRings;
    ofParameter<int> nElements;
    
    //Modes
    bool bMouse;
    
    
    //Export
    bool bSave;
    int                 snapCounter;
    string              snapString;
    ofImage             img;
    ofTrueTypeFont      cooper;
    bool                bSnapshot;
    float               phase;
		
};
