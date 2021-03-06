#pragma once

#include "ofMain.h"
#include "measureBar.h"
#include "unitCircle.h"
#include "cartesianPlane.h"
#include "textDisplay.h"
#include "arduinoReader.hpp"
#include "baseScene.h"



class templateScene : public baseScene{

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
    
    
    ofVec2f scr; //screen size
    ofVec2f scrCenter;
    
    //circle
    unitCircle mainCircle;
    
    //cartesian
    cartesianPlane plane;
    
    ofVec2f circleOrigin;
    float circleRadius;
    float angle;
    float sine, cosine;
    
    ofColor sinColor, cosColor;
    
    
    measureBar sineBar, cosineBar;
    
    ///Fonts
    ofTrueTypeFont fontLight;
    textDisplay textBox;

    
    ///ARDUINO
    arduinoReader arduino;
    
    int angleInput;
    string angleInputName;
    bool bShowRawinfo;
    
    float lastCycleTime;
    float cycleDuration;
    


		
};


