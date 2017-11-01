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
    
    int nElements;
    ofPoint origin;
    ofVec2f pos;
    vector<ofPoint> positions;
    float radius;
    float rad;
    
    float speed;
    ofColor c;
    
    ofVec2f res;
    
    ofxPanel gui;
    ofParameter<float> radX;
    ofParameter<float> radY;
    ofParameter<float> freqParam;
    ofParameter<float> ampParam;
    ofParameter<int> nRings;
    ofParameter<float> gap;
    ofParameter<float> thickness;
    
    
    //Export
    bool bSave;
    int                 snapCounter;
    string              snapString;
    ofImage             img;
    ofTrueTypeFont      cooper;
    bool                bSnapshot;
    float               phase;
    

		
};
