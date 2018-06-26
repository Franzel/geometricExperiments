#pragma once

#include "ofMain.h"
struct line {
    ofVec2f begin;
    ofVec2f end;
    float length;
    float thickness;
    ofVec2f dir;
    float dot;
    ofVec2f ctr;
    
};

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
    
    
    ofVec2f baseOrigin;
    ofVec2f baseEnd;
    ofVec2f baseVector;
    float baseAngle;
    
    ofVec2f rayOrigin;
    ofVec2f rayEnd;
    ofVec2f rayVector;
    float rayAngle;
    
    ofVec2f center;
    float baseLength;
    
    float distToZeroX;
    float distToZeroY;
    
    float dot;
    
    bool bMoveOrigin;
    bool bMoveEnd;
    bool bAutoRay;
    
    vector<line> lines;
    
		
};
