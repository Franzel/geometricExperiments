//
//  arduinoReader.cpp
//  sin_01
//
//  Created by Francisco Zamorano on 5/31/18.
//

#include "arduinoReader.hpp"

arduinoReader::arduinoReader(){
    ang = 0;
    
}

void arduinoReader::setup(){
    serial.setup("/dev/tty.usbmodem1411", 9600);

    
}
void arduinoReader::update(){
    if (serial.available() < 0) {
        msg = "Arduino Error";
    }
    else {
        //While statement looping through serial messages when serial is being provided.
        while (serial.available() > 0) {
            //byte data is being writen into byteData as int.
            byteData = serial.readByte();
            
            //byteData is converted into a string for drawing later.
            msg = "cm: " + ofToString(byteData);
        }
    }
    
    ang = ofMap(byteData,0,255,0,TWO_PI, true);
    
}
float arduinoReader::rotaryAngle(){
    return ang;
}
