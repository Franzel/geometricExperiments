//
//  measureBar.hpp
//  sincos_04
//
//  Created by Francisco Zamorano on 22-05-18.
//
//

#ifndef measureBar_hpp
#define measureBar_hpp

#include <stdio.h>
#include "ofmain.h"

class measureBar {
    measureBar();
    
public:
    float scale;
    float width, height;
    float posX, posY;
    ofColor color;
};

#endif /* measureBar_hpp */
