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
    
    ofDrawBitmapString(name, -longitude-50, thickness);
    ofDrawBitmapString("-1", -longitude, thickness*2);
    ofDrawBitmapString("0", 0, thickness*2);
    ofDrawBitmapString("1", longitude, thickness*2);
    
    ofPopMatrix();
}
