//
//  unitCircle.cpp
//  sin_01
//
//  Created by Francisco Zamorano on 22-05-18.
//
//

#include "unitCircle.h"


unitCircle::unitCircle(){
    
    
}

void unitCircle::setup(ofVec2f _ctr, float _radius){
    circleOrigin = _ctr;
    circleRadius = _radius;
    angle = 0;
    
}

void unitCircle::update(float _angle){
    angle = _angle;
    
}

void unitCircle::draw(){
    
    ofSetColor(0);
    ofNoFill();
    ofSetLineWidth(3);
    ofDrawCircle(circleOrigin, circleRadius);
    
    ofFill();
    ofDrawCircle(circleOrigin, circleRadius/64);
    
    float x = circleOrigin.x + cos(angle) * circleRadius;
    float y = circleOrigin.y + -sin(angle) * circleRadius;
    ofVec2f angPos;
    angPos.set(x,y);
    
    ofDrawLine(circleOrigin, angPos ); //main angle line
    ofSetColor(ofColor::red);
    ofDrawLine(angPos.x,angPos.y, angPos.x, circleOrigin.y);
    
    ofSetColor(ofColor::blue);
    ofDrawLine(circleOrigin.x, circleOrigin.y, angPos.x, circleOrigin.y);
    
    
}


