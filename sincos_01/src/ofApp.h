#pragma once

#include "ofMain.h"

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
    
    float angle;
    int nElements;
    float speed;
    float posX, posY;
    float size;
    float radius;
    ofVec2f origin;
    ofVec2f pos;
    ofColor c;
    
    
    //Fbo
    ofVec2f res;
    ofFbo fbo;
    ofShader shader;

    //Export
    bool bSave;
    int                 snapCounter;
    string              snapString;
    ofImage             img;
    ofTrueTypeFont      cooper;
    bool                bSnapshot;
    float               phase;
    
    
		
};
