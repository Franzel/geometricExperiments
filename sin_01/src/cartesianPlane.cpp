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
    
    float fontSize = 24;
    valueText.load("GT-America-Mono-Medium.otf", fontSize/2, true, true);
    valueText.setLineHeight(fontSize);
    valueText.setLetterSpacing(1.0);
    
    valueTextBig.load("GT-America-Mono-Medium.otf", fontSize * 0.6 , true, true);
    valueTextBig.setLineHeight(fontSize);
    valueTextBig.setLetterSpacing(1.0);
    
    valueTextSmall.load("GT-America-Mono-Medium.otf", fontSize/3, true, true);
    valueTextSmall.setLineHeight(fontSize);
    valueTextSmall.setLetterSpacing(1.0);

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

void cartesianPlane::drawXinfo(bool bTitle, bool bNumbers){
    float thickness = 10;

    if (bTitle) {
        ofSetColor(0,0,255);
        valueTextBig.drawString("EJE X", circleOrigin.x+circleRadius+thickness*2, circleOrigin.y+thickness/2);
    }

    if(bNumbers){
        ofSetColor(c);
        valueText.drawString("-1", circleOrigin.x-circleRadius-thickness*1.5, circleOrigin.y+thickness*3);
        valueText.drawString("1", circleOrigin.x+circleRadius, circleOrigin.y+thickness*3);
        valueText.drawString("0", circleOrigin.x-thickness, circleOrigin.y+thickness*3);
        valueText.drawString("-0.5", circleOrigin.x-circleRadius/2-thickness*2.5, circleOrigin.y+thickness*3);
        valueText.drawString("0.5", circleOrigin.x+circleRadius/2-thickness*1.5, circleOrigin.y+thickness*3);
    }

}


void cartesianPlane::drawYinfo(bool bTitle, bool bNumbers){
    float thickness = 10;
    
    if(bTitle){
        ofSetColor(255,0,0);
        valueTextBig.drawString("EJE Y", circleOrigin.x-thickness*3, circleOrigin.y-circleRadius-thickness*4);
    }

    if(bNumbers){
        ofSetColor(c);
        valueText.drawString("1", circleOrigin.x-thickness*2.5, circleOrigin.y-circleRadius+thickness/2);
        valueText.drawString("-1", circleOrigin.x-thickness*3.5, circleOrigin.y+circleRadius+thickness/2);
        valueText.drawString("0", circleOrigin.x-thickness*2.5, circleOrigin.y+thickness/2);
        valueText.drawString("0.5", circleOrigin.x-thickness*4.5, circleOrigin.y-circleRadius/2+thickness/2);
        valueText.drawString("-0.5", circleOrigin.x-thickness*6, circleOrigin.y+circleRadius/2+thickness/2);
    }

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
    valueText.drawString(ofToString(length,2), circleOrigin.x+thickness*2.5 , circleOrigin.y-circleRadius*length);
}

void cartesianPlane::drawXvalue(){
    ofSetColor(0,0,255);
    float thickness = 10;
    float length = cos(angle);
    valueText.drawString(ofToString(length,2), circleOrigin.x+circleRadius*length, circleOrigin.y-thickness*2);
}


