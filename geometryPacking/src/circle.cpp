//
//  circle.cpp
//  geometryPacking
//
//  Created by Francisco Zamorano on 9/10/18.
//
//

#include "circle.hpp"

circle::circle(){
    
    
}

void circle::setup(float _x, float _y){
    growing = true;
    x = _x;
    y = _y;
    r = 1;
    minRadius = 1;
    maxRadius = 30;
    col.setHsb(0, 0, 360);
}

void circle::update(){
    
    
}


void circle::grow(){
    if (growing && r >= minRadius && r<maxRadius ){
        r+=3;
    }
    col.setSaturation(r*8);
}
void circle::draw(){
    ofSetLineWidth(2);
//    ofNoFill();
    ofSetColor(col);
    ofDrawCircle(x, y, r);
    
}

bool circle::edges(){
    
    return (x+r > ofGetWidth() || x -r < 0 || y + r > ofGetHeight() || y -r < 0);
    
}
