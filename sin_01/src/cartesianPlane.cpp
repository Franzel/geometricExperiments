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

void cartesianPlane::update(float _angle){
    angle = _angle;
    
}


void cartesianPlane::drawX(){
    
    ofSetColor(c);
    ofSetLineWidth(1);
   
    ofDrawLine(circleOrigin.x, circleOrigin.y -circleRadius, circleOrigin.x, circleOrigin.y +circleRadius  ); //main angle line

 
}

void cartesianPlane::drawY(){
    
    ofSetColor(c);
    ofSetLineWidth(1);

    ofDrawLine(circleOrigin.x-circleRadius, circleOrigin.y , circleOrigin.x+circleRadius, circleOrigin.y   ); //main angle line
    
}

void cartesianPlane::drawSine(){
    
    ofSetColor(255,0,0);
    ofSetLineWidth(3);
    float length = -sin(angle) * circleRadius;
    ofDrawLine(circleOrigin.x, circleOrigin.y , circleOrigin.x, circleOrigin.y + length); //main angle line

    
}


void cartesianPlane::drawCosine(){
    
    ofSetColor(0,0,255);
    ofSetLineWidth(3);
    float length = cos(angle) * circleRadius;
    ofDrawLine(circleOrigin.x, circleOrigin.y , circleOrigin.x + length, circleOrigin.y); //main angle line

    
    
}

void cartesianPlane::drawXGrid(){
    
    ofSetColor(c);
    ofSetLineWidth(2);
    float thickness = 10;
    ofDrawLine(circleOrigin.x-thickness, circleOrigin.y-circleRadius , circleOrigin.x + thickness, circleOrigin.y-circleRadius); //main angle line
    ofDrawLine(circleOrigin.x-thickness, circleOrigin.y+circleRadius , circleOrigin.x + thickness, circleOrigin.y+circleRadius); //main angle line
    ofDrawLine(circleOrigin.x-thickness, circleOrigin.y , circleOrigin.x + thickness, circleOrigin.y); //main angle line
    ofDrawLine(circleOrigin.x-thickness, circleOrigin.y-circleRadius/2 , circleOrigin.x + thickness, circleOrigin.y-circleRadius/2); //main angle line
    ofDrawLine(circleOrigin.x-thickness, circleOrigin.y+circleRadius/2 , circleOrigin.x + thickness, circleOrigin.y+circleRadius/2); //main angle line

}

void cartesianPlane::drawYGrid(){
    
    ofSetColor(c);
    ofSetLineWidth(2);
    float thickness = 10;
    ofDrawLine(circleOrigin.x-circleRadius, circleOrigin.y-thickness , circleOrigin.x-circleRadius, circleOrigin.y + thickness); //main angle line
    ofDrawLine(circleOrigin.x+circleRadius, circleOrigin.y-thickness , circleOrigin.x+circleRadius, circleOrigin.y + thickness); //main angle line
    ofDrawLine(circleOrigin.x, circleOrigin.y-thickness , circleOrigin.x, circleOrigin.y + thickness); //main angle line
    ofDrawLine(circleOrigin.x-circleRadius/2, circleOrigin.y-thickness , circleOrigin.x-circleRadius/2, circleOrigin.y + thickness); //main angle line
    ofDrawLine(circleOrigin.x+circleRadius/2, circleOrigin.y-thickness , circleOrigin.x+circleRadius/2, circleOrigin.y + thickness); //main angle line
    


    
}

void cartesianPlane::drawXvalue(){
    float thickness = 10;
    float length = sin(angle);
    ofDrawBitmapString(ofToString(length,2), circleOrigin.x+thickness*2.5 , circleOrigin.y+circleRadius*length);
}

void cartesianPlane::drawYvalue(){
    float thickness = 10;
    float length = cos(angle);
    ofDrawBitmapString(ofToString(length,2), circleOrigin.x+circleRadius*length, circleOrigin.y-thickness*2);
}


