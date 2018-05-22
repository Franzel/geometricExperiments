//
//  measureBar.hpp
//  sincos_04
//
//  Created by Francisco Zamorano on 22-05-18.
//
//

#ifndef measureBar_hpp
#define measureBar_hpp

#include <stdio.h>
#include "ofMain.h"

class measureBar {
    
public:
    
    measureBar();
    
    void setup(ofVec2f _pos, float _maxLongitude, float _maxThickness, float _orientation, ofColor _color, string _name);
    void update(float magnitude);
    void draw();
    
    float scale;
    float longitude, thickness;
    ofVec2f pos;
    ofColor color;
    float orientation;
    float magnitude;
    string name;
};

#endif /* measureBar_h */
