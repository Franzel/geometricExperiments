//
//  measureBar.cpp
//  sin_01
//
//  Created by Francisco Zamorano on 22-05-18.
//
//

#include "measureBar.h"

measureBar::measureBar(){
    pos.set(100,100);
    longitude = 100;
    thickness = 100;
    orientation = 90;
    name = " ";
    
    float fontSize = 24;
    fontLight.load("GT-America-Mono-Medium.otf", fontSize, true, true);
    fontLight.setLineHeight(fontSize);
    fontLight.setLetterSpacing(1.0);
    
    fontSmall.load("GT-America-Mono-Medium.otf", fontSize/2, true, true);
    fontSmall.setLineHeight(fontSize/2);
    fontSmall.setLetterSpacing(1.0);

    
}


void measureBar::setup(ofVec2f _pos, float _maxLongitude, float _maxThickness, float _orientation, ofColor _color, string _name){
    
    pos = _pos;
    longitude = _maxLongitude;
    thickness = _maxThickness;
    orientation = _orientation;
    color = _color;
    name = _name;
}

void measureBar::update(float _magnitude){
    magnitude = _magnitude;
    
    
}

void measureBar::draw(){

    ofPushMatrix();
    ofTranslate(pos);
    ofRotate(orientation);
    
    ofSetColor(0);
    ofSetLineWidth(0.5);
    ofDrawLine(-longitude,thickness/2,longitude,thickness/2);

    ofSetColor(color);
    ofDrawRectangle(0,0, longitude * magnitude, thickness);
    
    ofPushMatrix();
    ofTranslate(0, thickness*2);
    ofRotate(-orientation);
    fontSmall.drawString("-1", -longitude, thickness*2);
    fontSmall.drawString("0", 0, thickness*2);
    fontSmall.drawString("1", longitude, thickness*2);
    ofPopMatrix();
    
    //text info
    ofPushMatrix();
    ofTranslate(longitude * magnitude , -fontLight.getLineHeight()/2 - orientation/2);
    ofRotate(-orientation);
    fontSmall.drawString(name, 0, -fontLight.getLineHeight()*1.5);
    fontLight.drawString(ofToString(magnitude,3), 0,0);
    ofPopMatrix();
    
    ofPopMatrix();
    

}
