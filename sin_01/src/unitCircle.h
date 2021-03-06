//
//  unitCircle.hpp
//  sin_01
//
//  Created by Francisco Zamorano on 22-05-18.
//
//

#ifndef unitCircle_hpp
#define unitCircle_hpp

#include <stdio.h>
#include "ofMain.h"

class unitCircle{
public:
    
    unitCircle();
    
    void setup(ofVec2f _ctr, float _radius);
    void update(float _angle);
    void draw();
    void draw(bool bGuides, bool bAngleText, int nDivisions);
    void drawAngleTip(ofVec2f _pos, ofColor col, bool bDdrawCos, bool bDrawSin);
    void drawAngleArc();
    void displayAngle();
    void drawSine();
    void drawCosine();
    void drawDottedX();
    void drawDottedY();
    
    
    ofVec2f circleOrigin;
    float circleRadius;
    float angle;
    
    ofTrueTypeFont font;
    ofTrueTypeFont fontSmall;

    ofVec2f angPos;

    
    
};




#endif /* unitCircle_h */
