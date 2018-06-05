//
//  textDisplay.cpp
//  sin_01
//
//  Created by Francisco Zamorano on 30-05-18.
//
//

#include "textDisplay.h"


textDisplay::textDisplay(){
    
    int bodyFontSize = 18;
    
    bodyFont.load("GT-America-Mono-Medium.otf", bodyFontSize, true, true);

}

void textDisplay::setup(string file){
    img.load(file);

    
}

void textDisplay::update(){
    
    
}

void textDisplay::drawText(){
    bodyFont.drawString("testing text \n testing texttext2", 1000, 100);
    
    
}

void textDisplay::drawImage(){
    ofPushStyle();
    ofSetColor(255);
    img.draw(1080,0, 960, 1080);
    ofPopStyle();
    
}
