//
//  cartesianPlane.hpp
//  sin_01
//
//  Created by Francisco Zamorano on 22-05-18.
//
//

#ifndef cartesianPlane_hpp
#define cartesianPlane_hpp

#include <stdio.h>
#include "ofMain.h"

class cartesianPlane {
    
    
public:
    cartesianPlane();
    
    void setup(ofVec2f _ctr, float _radius, float _magnitude);
    void update(float _angle);
    void drawX();
    void drawY();
    void drawSine();
    void drawCosine();
    void drawXGrid();
    void drawYGrid();
    void drawXinfo(bool bTitle, bool bNumbers);
    void drawYinfo(bool bTitle, bool bNumbers);

    
    void drawXvalue();
    void drawYvalue();
    void drawBgGrid();
    
    ofVec2f circleOrigin;
    float circleRadius;
    float angle;
    ofColor c;
    
    ofTrueTypeFont valueText;
    ofTrueTypeFont valueTextBig;
    ofTrueTypeFont valueTextSmall;
};



#endif /* cartesianPlane_h */
