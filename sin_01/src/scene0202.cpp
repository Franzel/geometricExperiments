#include "scene0202.h"

//--------------------------------------------------------------
void scene0202::setup(ofVec2f res, float rad){
    
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
void scene0202::update(float ang){
    
    cosine = cos(ang);
    sine = sin(ang);
    cosineBar.update(cosine);
    sineBar.update(sine);
    mainCircle.update(ang);
    plane.update(ang);
    
}

//--------------------------------------------------------------
void scene0202::draw(){
    
    plane.drawX();
    plane.drawY();
    plane.drawYGrid();
    plane.drawXGrid();

    mainCircle.drawDottedY();
    mainCircle.drawCosine();
    mainCircle.draw(true,true,24);
    cosineBar.draw();

    mainCircle.drawAngleArc();
    ofVec2f tempPos;
    tempPos.set(circleOrigin.x + cosine*circleRadius, circleOrigin.y - sine*circleRadius);
    mainCircle.drawAngleTip(tempPos, ofColor(20), false, false);
    mainCircle.displayAngle();
//    textBox.drawImage();

    
}

//--------------------------------------------------------------
void scene0202::keyPressed(int key){

}
