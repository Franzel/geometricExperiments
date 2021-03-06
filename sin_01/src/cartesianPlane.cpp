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
        valueTextBig.drawString("EJE X", circleOrigin.x+circleRadius-thickness*15, circleOrigin.y+thickness*8);
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
        valueTextBig.drawString("EJE Y", circleOrigin.x-thickness*14, circleOrigin.y-circleRadius/2+thickness/2);
    }

    if(bNumbers){
        ofSetColor(c);
        valueText.drawString("1", circleOrigin.x-thickness*2.5, circleOrigin.y-circleRadius+thickness);
        valueText.drawString("-1", circleOrigin.x-thickness*3.5, circleOrigin.y+circleRadius);
        valueText.drawString("0", circleOrigin.x-thickness*2.5, circleOrigin.y+thickness/2);
        valueText.drawString("0.5", circleOrigin.x-thickness*4.5, circleOrigin.y-circleRadius/2+thickness/2);
        valueText.drawString("-0.5", circleOrigin.x-thickness*6, circleOrigin.y+circleRadius/2+thickness/2);
    }

}

void cartesianPlane::drawXGrid(){
    
    ofSetColor(c);
    ofSetLineWidth(2);
    float thickness = 10;
    
    ofVec2f negMax =ofVec2f(circleOrigin.x-circleRadius, circleOrigin.y);
    ofVec2f posMax =ofVec2f(circleOrigin.x+circleRadius, circleOrigin.y);
    ofVec2f perpendicular = ofVec2f(0,thickness/2);
    float longitude = negMax.distance(circleOrigin);
    ofVec2f quarter = ofVec2f(longitude/2,0);
   
    ofDrawLine(negMax,posMax);
    ofDrawLine(circleOrigin-perpendicular,circleOrigin+perpendicular);
    ofDrawLine(negMax-perpendicular,negMax+perpendicular);
    ofDrawLine(negMax + quarter-perpendicular,negMax+quarter+perpendicular);
    ofDrawLine(posMax - quarter-perpendicular,posMax-quarter+perpendicular);
    ofDrawLine(posMax-perpendicular,posMax+perpendicular);

}

void cartesianPlane::drawYGrid(){
    
    ofSetColor(c);
    ofSetLineWidth(2);
    float thickness = 10;
    
    ofVec2f negMax =ofVec2f(circleOrigin.x, circleOrigin.y-circleRadius);
    ofVec2f posMax =ofVec2f(circleOrigin.x, circleOrigin.y+circleRadius);
    ofVec2f perpendicular = ofVec2f(thickness/2,0);
    float longitude = negMax.distance(circleOrigin);
    ofVec2f quarter = ofVec2f(0,longitude/2);
    
    ofDrawLine(negMax,posMax);
    ofDrawLine(circleOrigin-perpendicular,circleOrigin+perpendicular);
    ofDrawLine(negMax-perpendicular,negMax+perpendicular);
    ofDrawLine(negMax + quarter-perpendicular,negMax+quarter+perpendicular);
    ofDrawLine(posMax - quarter-perpendicular,posMax-quarter+perpendicular);
    ofDrawLine(posMax-perpendicular,posMax+perpendicular);
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
    valueText.drawString(ofToString(length,2), circleOrigin.x+thickness*2.5 , circleOrigin.y-circleRadius*(length*0.9)+10);
}

void cartesianPlane::drawXvalue(){
    ofSetColor(0,0,255);
    float thickness = 10;
    float length = cos(angle);
    valueText.drawString(ofToString(length,2), circleOrigin.x+circleRadius*(length*0.9)-20, circleOrigin.y-thickness*2);
}


