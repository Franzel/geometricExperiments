//
//  cartesianPlane.cpp
//  sin_01
//
//  Created by Francisco Zamorano on 22-05-18.
//
//

#include "cartesianPlane.h"

cartesianPlane::cartesianPlane(){
    c.set(ofColor::gray);
    
}


void cartesianPlane::setup(ofVec2f _ctr, float _radius, float _magnitude){
    circleOrigin = _ctr;
    circleRadius = _radius * _magnitude;
    
}


void cartesianPlane::draw(){
    
    ofSetColor(c);
    ofSetLineWidth(1);
   
    ofDrawLine(circleOrigin.x, circleOrigin.y -circleRadius, circleOrigin.x, circleOrigin.y +circleRadius  ); //main angle line
    ofDrawLine(circleOrigin.x-circleRadius, circleOrigin.y , circleOrigin.x+circleRadius, circleOrigin.y   ); //main angle line
 
    
}
