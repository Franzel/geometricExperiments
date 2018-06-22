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

    while (serial.available()) {
        buffer.push_back(serial.readByte());
    }
    
    // Use an iterator for looping so part of the buffer can safely be erased
    // while looping through it
    for (auto iter = buffer.begin(); iter != buffer.end(); iter++) {
        // Check each byte until a newline is hit
        if (*iter == '\n') {
            // Assign the first line to a different buffer
            // At this point the buffer may look like
            // '1' '5' '7' '\n' '1' '5' '5' '\n' '1' '5' '4' '\n'
            // and only the first value is desired at this point
            vector<char> line;
            line.assign(buffer.begin(), iter);
            
            // Use atoi() to convert from ascii string to integer
            // e.g. convert a series of bytes: '1' '5' '7'
            // into the integer: 157
            if (line.size() > 0) {
                value = atoi(line.data());
                ofLog() << value;
                //cout<< value<<endl;
            }
            
            // Remove this line from the buffer
            if (buffer.size() > 1) {
                iter = buffer.erase(buffer.begin(), iter);
            }
        }
    }
    
    
    ang = ofMap(value,0,720,0,TWO_PI);
    
}
float arduinoReader::rotaryAngle(){
    return ang;
}
