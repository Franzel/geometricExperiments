#include "scene0104.h"

//--------------------------------------------------------------
void scene0104::setup(){
    
    scr.set(ofGetScreenWidth(), ofGetScreenHeight());
    ofSetWindowShape(scr.x, scr.y);
    ofSetFullscreen(true);
    scrCenter.set(scr/2);
    
    ofSetBackgroundColor(255, 240, 230);
    
    
    ///colors
    sinColor = ofColor(ofColor::red);
    cosColor = ofColor(ofColor::blue);
    
    ///Circle
    ofSetCircleResolution(100);
    circleOrigin.set(scrCenter.x/3 *1.5, scrCenter.y);
    circleRadius = scr.y/3;
    angle=0;
    
    plane.setup(circleOrigin, scr.y/3, 1.0); //cartesian plane
    mainCircle.setup(circleOrigin, scr.y/3); //circle setup
    
    lastCycleTime = ofGetElapsedTimef();
    cycleDuration = TWO_PI;
    
    ///measure Bars
    sineBar.setup(ofVec2f(circleOrigin + ofVec2f(circleRadius+100,0)), circleRadius,10,-90, sinColor, "SIN");
    cosineBar.setup(ofVec2f(circleOrigin + ofVec2f(0,circleRadius+100)), circleRadius,10,0, cosColor, "COS");
    
    ///INFO
    textBox.setup("info_01-04.png");
    bShowRawinfo = false;
    
    ///ARDUINO
    arduino.setup();
    
    ///INPUTS
    angleInput = 0;
    angleInputName = "mouse";
    
}

//--------------------------------------------------------------
void scene0104::update(){
    if(angleInput==0){
        angle = ofMap(ofGetMouseY(), 0, scr.y, 0, TWO_PI);//mouse
    }
    else if(angleInput==1){
        
        
        float diffTime = ofGetElapsedTimef() - lastCycleTime;
        if (diffTime > cycleDuration){
            lastCycleTime = ofGetElapsedTimef();
        }
        angle = diffTime;
    }
    else if(angleInput==2){
        arduino.update();
        angle = arduino.rotaryAngle();
    }
    else {
        angle = ofMap(ofGetMouseY(), 0, scr.y, 0, TWO_PI);//mouse
    }

    cosine = cos(angle);
    sine = sin(angle);
    cosineBar.update(cosine);
    sineBar.update(sine);
    mainCircle.update(angle);
    plane.update(angle);
    
}

//--------------------------------------------------------------
void scene0104::draw(){
    
    plane.drawBgGrid();
    plane.drawX();
    plane.drawY();
    plane.drawYGrid();
    plane.drawYinfo();
//    plane.drawXGrid();
    plane.drawSine();
//    plane.drawCosine();
    plane.drawYvalue();
    ofVec2f tempPos;
    tempPos.set(circleOrigin.x + cosine*circleRadius, circleOrigin.y - sine*circleRadius);
    
//    mainCircle.drawAngleArc();
//    mainCircle.displayAngle();
    mainCircle.draw();
    mainCircle.drawDottedX();
//    mainCircle.drawDottedY();
    mainCircle.drawAngleTip(tempPos,ofColor::red);
    
//    mainCircle.drawSine();
//    mainCircle.drawCosine();

//    cosineBar.draw();
//    sineBar.draw();
    textBox.drawImage();
    
    //raw numeric info
    if(bShowRawinfo){
        ofSetColor(ofColor::black);
        ofDrawBitmapString("ANGLE (deg) = " + ofToString(ofRadToDeg(angle),4), 100, 100);
        ofDrawBitmapString("angle (rad) = " + ofToString(angle,4), 100, 120);
        ofDrawBitmapString("sin         = " + ofToString(sin(angle),4), 100, 140);
        ofDrawBitmapString("cos         = " + ofToString(cos(angle),4), 100, 160);
        ofDrawBitmapString("Serial      = " + ofToString(arduino.byteData,4), 100, 180);
        ofDrawBitmapString("angle input = " + angleInputName, 100, 200);
    }
    
    
}

//--------------------------------------------------------------
void scene0104::keyPressed(int key){
    switch (key) {
        case '0':
            angleInput = 0;
            angleInputName = "mouse";
            break;
        case '1':
            angleInput = 1;
            angleInputName = "auto";
            break;
        case '2':
            angleInput = 2;
            angleInputName = "rotary";
            break;
        case 'i':
            bShowRawinfo = !bShowRawinfo;
            break;
        default:
            break;
    }
    
}
