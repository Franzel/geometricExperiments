#include "scene0102.h"

//--------------------------------------------------------------
void scene0102::setup(ofVec2f res, float rad){
    
    scr.set(res);
    scrCenter.set(scr/2);
    ofSetBackgroundColor(255, 240, 230);
    
    ///colors
    sinColor = ofColor(ofColor::red);
    cosColor = ofColor(ofColor::blue);
    
    ///Circle
    circleOrigin.set(scrCenter.x/3 *1.5, scrCenter.y);
    circleRadius = rad;
    angle=0;
    
    plane.setup(circleOrigin, circleRadius, 1.0); //cartesian plane
    mainCircle.setup(circleOrigin, circleRadius); //circle setup
    
    
    ///measure Bars
    sineBar.setup(ofVec2f(circleOrigin + ofVec2f(circleRadius+100,0)), circleRadius,10,-90, sinColor, "SIN");
    cosineBar.setup(ofVec2f(circleOrigin + ofVec2f(0,circleRadius+100)), circleRadius,10,0, cosColor, "COS");
    
    ///INFO
    textBox.setup("info_01-02.png");

}

//--------------------------------------------------------------
void scene0102::update(float ang){
    
    cosine = cos(ang);
    sine = sin(ang);
    cosineBar.update(cosine);
    sineBar.update(sine);
    mainCircle.update(ang);
    plane.update(ang);
    
}

//--------------------------------------------------------------
void scene0102::draw(){
    
    plane.c = ofColor::gray;
    plane.drawBgGrid();
    plane.drawX();
    plane.drawXGrid();
    plane.drawXinfo(true, true);
    plane.drawXvalue();
    
    plane.c = ofColor::gray;
    plane.drawY();
    plane.drawYGrid();
    plane.drawCosine();

//    textBox.drawImage();

}

//--------------------------------------------------------------
void scene0102::keyPressed(int key){

}
