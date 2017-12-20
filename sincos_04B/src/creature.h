//
//  creature.h
//  sincos_04
//
//  Created by Francisco Zamorano on 20-12-17.
//
//

#ifndef creature_h
#define creature_h




#include "ofMain.h"

class Creature {
    
public:
    
    Creature(int nR, int nE, float rX, float rY, float sp, float am, float fr );
    
    void setup();
    void draw();
    
    ofVec3f center;
    float maxRadX;
    float maxRadY;
    float freq;
    float amp;
    float speed;
    
    int nRings;
    int nElements;
    
    
};
#endif /* creature_h */
