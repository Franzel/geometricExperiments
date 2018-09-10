//
//  circle.hpp
//  geometryPacking
//
//  Created by Francisco Zamorano on 9/10/18.
//
//

#ifndef circle_hpp
#define circle_hpp

#include <stdio.h>

#include "ofMain.h"

class circle {
    
    
    
public:
    float x, y, r;
    float minRadius, maxRadius;
    circle();
    void setup(float _x, float _y);
    void grow();
    void update();
    void draw();
    bool edges();
    bool growing;
    int id;
    ofColor col;
};

#endif /* circle_hpp */
