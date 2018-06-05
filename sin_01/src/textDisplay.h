//
//  textDisplay.h
//  sin_01
//
//  Created by Francisco Zamorano on 30-05-18.
//
//


#ifndef textDisplay_h
#define textDisplay_h

#include <stdio.h>
#include "ofMain.h"

class textDisplay{
    public:
    
    textDisplay();
    
    void setup(string file);
    void update();
    void drawText();
    void drawImage();
    
    string title;
    string body;
    
    
    
    ofTrueTypeFont titleFont;
    ofTrueTypeFont bodyFont;
    ofTrueTypeFont captionFont;
    
    ofImage img;
    
    
};

#endif /* textDisplay_h */
