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
    
    void setup();
    void update();
    void draw ();
    
    string title;
    string body;
    
    
    
    ofTrueTypeFont titleFont;
    ofTrueTypeFont bodyFont;
    ofTrueTypeFont captionFont;
    
    
};

#endif /* textDisplay_h */
