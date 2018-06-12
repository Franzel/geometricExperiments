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


void cartesianPlane::drawY(){
    
    ofSetColor(c);
    ofSetLineWidth(1);
    ofDrawLine(circleOrigin.x, circleOrigin.y -circleRadius, circleOrigin.x, circleOrigin.y +circleRadius  );
}

void cartesianPlane::drawX(){
    
    ofSetColor(c);
    ofSetLineWidth(1);
    ofDrawLine(circleOrigin.x-circleRadius, circleOrigin.y , circleOrigin.x+circleRadius, circleOrigin.y   );
}

void cartesianPlane::drawSine(){

    ofSetLineWidth(6);
    float length = -sin(angle) * circleRadius;
    if(length<0){
        ofSetColor(255,0,0);
    }else{
        ofSetColor(150, 0, 0);
    }
    ofDrawLine(circleOrigin.x, circleOrigin.y , circleOrigin.x, circleOrigin.y + length);
}


void cartesianPlane::drawCosine(){
    
    ofSetLineWidth(6);
    float length = cos(angle) * circleRadius;
    if(length>0){
        ofSetColor(0,0,255);
    }else{
        ofSetColor(0, 0, 120);
    }
    ofDrawLine(circleOrigin.x, circleOrigin.y , circleOrigin.x + length, circleOrigin.y);
}

void cartesianPlane::drawXinfo(){
    
    ofSetColor(c);
    float thickness = 10;
    
    ofDrawBitmapString("eje X", circleOrigin.x+circleRadius+thickness*2, circleOrigin.y);
    ofDrawBitmapString("-1", circleOrigin.x-circleRadius-thickness, circleOrigin.y+thickness*3);
    ofDrawBitmapString("1", circleOrigin.x+circleRadius+thickness/2, circleOrigin.y+thickness*3);
    ofDrawBitmapString("0", circleOrigin.x-thickness, circleOrigin.y+thickness*3);
    ofDrawBitmapString("-0.5", circleOrigin.x-circleRadius/2-thickness*2, circleOrigin.y+thickness*3);
    ofDrawBitmapString("0.5", circleOrigin.x+circleRadius/2-thickness, circleOrigin.y+thickness*3);
}


void cartesianPlane::drawYinfo(){
    
    ofSetColor(c);
    float thickness = 10;
    
    ofDrawBitmapString("eje Y", circleOrigin.x-thickness*2, circleOrigin.y-circleRadius-thickness*2);
    
    ofDrawBitmapString("-1", circleOrigin.x-thickness*3, circleOrigin.y-circleRadius+thickness/2);
    ofDrawBitmapString("1", circleOrigin.x-thickness*3, circleOrigin.y+circleRadius+thickness/2);
    ofDrawBitmapString("0", circleOrigin.x-thickness*3, circleOrigin.y);
    ofDrawBitmapString("-0.5", circleOrigin.x-thickness*4, circleOrigin.y-circleRadius/2);
    ofDrawBitmapString("0.5", circleOrigin.x-thickness*4, circleOrigin.y+circleRadius/2);
}

void cartesianPlane::drawXGrid(){
    
    ofSetColor(c);
    ofSetLineWidth(2);
    float thickness = 10;
    
    ofDrawLine(circleOrigin.x-circleRadius, circleOrigin.y-thickness , circleOrigin.x-circleRadius, circleOrigin.y + thickness);
    ofDrawLine(circleOrigin.x+circleRadius, circleOrigin.y-thickness , circleOrigin.x+circleRadius, circleOrigin.y + thickness);
    ofDrawLine(circleOrigin.x, circleOrigin.y-thickness , circleOrigin.x, circleOrigin.y + thickness);
    ofDrawLine(circleOrigin.x-circleRadius/2, circleOrigin.y-thickness/2 , circleOrigin.x-circleRadius/2, circleOrigin.y + thickness/2);
    ofDrawLine(circleOrigin.x+circleRadius/2, circleOrigin.y-thickness/2 , circleOrigin.x+circleRadius/2, circleOrigin.y + thickness/2);
}

void cartesianPlane::drawYGrid(){
    
    ofSetColor(c);
    ofSetLineWidth(2);
    float thickness = 10;
    
    ofDrawLine(circleOrigin.x-thickness, circleOrigin.y-circleRadius , circleOrigin.x + thickness, circleOrigin.y-circleRadius);
    ofDrawLine(circleOrigin.x-thickness, circleOrigin.y+circleRadius , circleOrigin.x + thickness, circleOrigin.y+circleRadius);
    ofDrawLine(circleOrigin.x-thickness, circleOrigin.y , circleOrigin.x + thickness, circleOrigin.y);
    ofDrawLine(circleOrigin.x-thickness/2, circleOrigin.y-circleRadius/2 , circleOrigin.x + thickness/2, circleOrigin.y-circleRadius/2);
    ofDrawLine(circleOrigin.x-thickness/2, circleOrigin.y+circleRadius/2 , circleOrigin.x + thickness/2, circleOrigin.y+circleRadius/2);
}

void cartesianPlane::drawBgGrid(){
    
    ofSetColor(230);
    ofSetLineWidth(0.2);
    float thickness = 10;
    
    ofDrawLine(circleOrigin.x-circleRadius, circleOrigin.y-circleRadius, circleOrigin.x+circleRadius, circleOrigin.y-circleRadius);
    ofDrawLine(circleOrigin.x-circleRadius, circleOrigin.y-circleRadius/2, circleOrigin.x+circleRadius, circleOrigin.y-circleRadius/2);
    ofDrawLine(circleOrigin.x-circleRadius, circleOrigin.y+circleRadius/2, circleOrigin.x+circleRadius, circleOrigin.y+circleRadius/2);
    ofDrawLine(circleOrigin.x-circleRadius, circleOrigin.y+circleRadius, circleOrigin.x+circleRadius, circleOrigin.y+circleRadius);
    
    
    ofDrawLine(circleOrigin.x-circleRadius, circleOrigin.y-circleRadius, circleOrigin.x-circleRadius, circleOrigin.y+circleRadius);
    ofDrawLine(circleOrigin.x-circleRadius/2, circleOrigin.y-circleRadius, circleOrigin.x-circleRadius/2, circleOrigin.y+circleRadius);
    ofDrawLine(circleOrigin.x+circleRadius/2, circleOrigin.y-circleRadius, circleOrigin.x+circleRadius/2, circleOrigin.y+circleRadius);
    ofDrawLine(circleOrigin.x+circleRadius, circleOrigin.y-circleRadius, circleOrigin.x+circleRadius, circleOrigin.y+circleRadius);
}


void cartesianPlane::drawYvalue(){
    float thickness = 10;
    float length = sin(angle);
    ofDrawBitmapString(ofToString(length,2), circleOrigin.x+thickness*2.5 , circleOrigin.y-circleRadius*length);
}

void cartesianPlane::drawXvalue(){
    ofSetColor(0,0,255);
    float thickness = 10;
    float length = cos(angle);
    ofDrawBitmapString(ofToString(length,2), circleOrigin.x+circleRadius*length, circleOrigin.y-thickness*2);
}


