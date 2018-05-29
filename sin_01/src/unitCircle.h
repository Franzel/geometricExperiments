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
    void drawAngleTip(ofVec2f _pos);
    void drawAngleArc();
    void displayAngle();
    
    ofVec2f circleOrigin;
    float circleRadius;
    float angle;
    
    ofTrueTypeFont font;
    
};




#endif /* unitCircle_h */
