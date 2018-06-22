//
//  arduinoReader.hpp
//  sin_01
//
//  Created by Francisco Zamorano on 5/31/18.
//

#ifndef arduinoReader_hpp
#define arduinoReader_hpp

#include <stdio.h>
#include "ofMain.h"

class arduinoReader {
    
    
public:
    arduinoReader();
    void setup();
    void update();
    float rotaryAngle();
    
    float ang;
    ofSerial serial;
    string msg;
    int byteData;
    
    vector<unsigned char> buffer;
    int value;

    
};

#endif /* arduinoReader_hpp */
