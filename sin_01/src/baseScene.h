


#ifndef _BASE_SCENE
#define _BASE_SCENE


#include "ofMain.h"


class baseScene {
	
	public: 
	
	virtual void setup(ofVec2f res, float rad){};
	virtual void update(float angle){};
	virtual void draw(){};
	
};

#endif
