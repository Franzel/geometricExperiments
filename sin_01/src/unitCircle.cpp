//
//  unitCircle.cpp
//  sin_01
//
//  Created by Francisco Zamorano on 22-05-18.
//
//

#include "unitCircle.h"


unitCircle::unitCircle(){
    float fontSize = 18;
    font.load("GT-America-Mono-Medium.otf", fontSize, true, true);
    font.setLineHeight(fontSize);
    font.setLetterSpacing(1.0);

    fontSmall.load("GT-America-Mono-Medium.otf", fontSize/2, true, true);
    fontSmall.setLineHeight(fontSize);
    fontSmall.setLetterSpacing(1.0);

    angPos.set(0,0);
    
}

void unitCircle::setup(ofVec2f _ctr, float _radius){
    circleOrigin = _ctr;
    circleRadius = _radius;
    angle = 0;
}

void unitCircle::update(float _angle){
    angle = _angle;
    
    float x = circleOrigin.x + cos(angle) * circleRadius;
    float y = circleOrigin.y + -sin(angle) * circleRadius;
    angPos.set(x,y);
    
}

void unitCircle::draw(){
    
    ofSetColor(255,50);
    ofDrawCircle(circleOrigin, circleRadius);

    ofNoFill();
    ofSetColor(0);
    ofSetLineWidth(2);
    ofDrawCircle(circleOrigin, circleRadius);
    
    ofFill();
    ofSetColor(0);
    ofDrawCircle(circleOrigin, circleRadius/64);
}

void unitCircle::draw(bool bGuides, bool bAngleText, int nDivisions){
    
    ofSetColor(255,50);
    ofDrawCircle(circleOrigin, circleRadius);
    
    ofNoFill();
    ofSetColor(0);
    ofSetLineWidth(2);
    ofDrawCircle(circleOrigin, circleRadius);
    
    ofFill();
    ofSetColor(0);
    ofDrawCircle(circleOrigin, circleRadius/64);
    
    if(bGuides){
        for(int i=0; i<nDivisions; i++){
            float theta = (TWO_PI / nDivisions) * i;
            float x = circleOrigin.x + cos(theta) * circleRadius;
            float y = circleOrigin.y + sin(theta) * circleRadius;
            
            ofVec2f tempPos;
            tempPos.set(x, y);
            
            ofVec2f diff = tempPos - circleOrigin;
            diff.normalize();
            
            diff*=6;
            
            ofSetLineWidth(1);
            ofSetColor(ofColor::gray);
            ofDrawLine(tempPos-diff, tempPos+diff);
        }
    }
    
    if(bAngleText){
        for(int i=0; i<nDivisions; i++){
            float theta = (TWO_PI / nDivisions) * i;
            float x = circleOrigin.x + cos(theta) * circleRadius;
            float y = circleOrigin.y + -sin(theta) * circleRadius;
            
            ofVec2f tempPos;
            tempPos.set(x, y);
            
            ofVec2f diff = tempPos - circleOrigin;
            diff.normalize();
            
            
            
            ofSetLineWidth(1);
            ofSetColor(ofColor::gray);
            float fontWidth = fontSmall.getStringBoundingBox(ofToString(ofRadToDeg(theta)),0,0).getWidth();
            float fontHeight = fontSmall.getStringBoundingBox(ofToString(ofRadToDeg(theta)),0,0).getHeight();
            
            diff*=10 + fontWidth;
            
            fontSmall.drawString(ofToString(ofRadToDeg(theta)), tempPos.x+diff.x , tempPos.y+diff.y);
        }
    }
    
}

void unitCircle::drawAngleTip(ofVec2f _pos, ofColor col, bool bDrawCos, bool bDrawSin){
    ofSetColor(col);
    ofDrawCircle(_pos,7.6);
    
    if(bDrawCos){
        ofDrawLine(circleOrigin.x, angPos.y, angPos.x, angPos.y);
    }
    
    if(bDrawSin){
        ofDrawLine(angPos.x, circleOrigin.y, angPos.x, angPos.y);
    }
}

void unitCircle::drawAngleArc(){
    ofPolyline curve;
    ofPolyline curve2;
    ofSetLineWidth(1);
    ofSetColor(155,120,100,60);

    if(angle>0){
        curve.addVertex(circleOrigin);
        curve.arc(circleOrigin, circleRadius,circleRadius, 0, ofRadToDeg(TWO_PI-angle),false, 360);
        curve.close();
        
        //copy info from ofPolyline above to draw fill
        ofBeginShape();
        for( int i = 0; i < curve.getVertices().size(); i++) {
            ofVertex(curve.getVertices().at(i).x, curve.getVertices().at(i).y);
        }
        ofEndShape();
        curve2.addVertex(circleOrigin);
        curve2.arc(circleOrigin, circleRadius/3,circleRadius/3, 0, ofRadToDeg(TWO_PI-angle),false, 360);
        curve2.close();
        curve2.draw();
    }
}


void unitCircle::displayAngle(){
    ofSetColor(0);
    float currDegrees = ofRadToDeg(angle);
    font.drawString(ofToString(currDegrees,1), circleOrigin.x + 20, circleOrigin.y - 20);
    
}

void unitCircle::drawSine(){
    //sine line
    ofSetColor(ofColor::red);
    ofSetLineWidth(1.5);
    ofDrawLine(angPos.x,angPos.y, angPos.x, circleOrigin.y);
    
}

void unitCircle::drawCosine(){
    //cosine line
    ofSetColor(ofColor::blue);
    ofSetLineWidth(1.5);
    ofDrawLine(circleOrigin.x, circleOrigin.y, angPos.x, circleOrigin.y);
    
}

void unitCircle::drawDottedX(){
    ofSetColor(ofColor::lightGray);
    ofSetLineWidth(1);
    ofDrawLine(circleOrigin.x-circleRadius, angPos.y, circleOrigin.x+circleRadius, angPos.y);
    
}

void unitCircle::drawDottedY(){
    ofSetColor(ofColor::lightGray);
    ofSetLineWidth(1);
    ofDrawLine(angPos.x, circleOrigin.y-circleRadius, angPos.x, circleOrigin.y+circleRadius);
    
}



