//
//  creature.cpp
//  sincos_04
//
//  Created by Francisco Zamorano on 20-12-17.
//
//

#include "creature.h"

Creature::Creature(int nR, int nE, float rX, float rY, float sp, float am, float fr ){
    maxRadX = rX;
    maxRadY = rY;
    freq = fr;
    amp = am;
    speed = sp;
    nRings = nR;
    nElements = nE;
    center.set(0,0,0);
    
}


void Creature::setup(){

    
    
}

void Creature::draw(){
    float time = ofGetElapsedTimef();
    
    for (int i=0; i<nRings ; i++){
        float angle = HALF_PI + PI/nRings * i;
        
        //Set position in X and Y
        float x = center.x + cos(angle) * maxRadX;
        float y = center.y + sin(angle) * maxRadY + sin(i*0.5+time)*10;
        
        float ringRadius = ofDist(center.x, center.y+y, x, center.y+y);
        
        //        //testing perpendicular radius calculation
        //        ofDrawCircle(x, y, 5);
        //        ofDrawLine(x, y, x+ringRadius*2, y);
        
        ringRadius += (sin(speed*time+i * freq)+1)/2 * amp;
        
        //Draw perpendicular circles
        ofPushMatrix();
        ofTranslate(center.x, y, center.z);
        ofRotateX(90);
        
        ofNoFill();
        ofSetLineWidth(1);
        ofFill();
        ofColor c;
        c.set(127+127*sin(speed*time + i*freq), 127+127*sin(speed*time + i*freq/2), 127+127*sin(i * 0.5 +time),100);
        ofSetColor(c);
        ofDrawCircle(0,0, ringRadius);
        ofPopMatrix();
        
        
        //Draw thorns
        for (int j=0; j<nElements ; j++){
            float angle2 = TWO_PI/nElements*j;
            float x2 = center.x + cos(angle2) * ringRadius + sin(speed*time)*5 ;
            float z  = center.z + sin(angle2) * ringRadius ;
            ofVec3f pos;
            pos.set(x2,y,z);
            c.setHsb(127+127*sin(i * 0.1 +time), 255, 127+127*sin(i * 0.5 +time));
            ofSetColor(c);
            ofDrawSphere(pos, 1 + sin(speed*time+i * freq*4)*0.5);
            ofVec3f diff = pos-center;
            diff.normalize();
            ofDrawLine( pos+diff* (15+sin(speed*time + i*freq)*15), pos+diff* (8+sin(speed*time + i*freq+FOUR_PI)*8));
        }
    }

    
    
}
