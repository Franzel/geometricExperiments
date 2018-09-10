#include "ofApp.h"


//based on example for processing by Daniel Shiffmann https://www.youtube.com/watch?v=QHEQuoIKgNE&t=214s

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(0);
    ofSetCircleResolution(60);
    maxRad = 200;
    ctr.set(ofGetWidth()/2, ofGetHeight()/2);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //ofSetColor(30,0, 0);
    //ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, maxRad);
    
    circle temp;
    float angle = ofRandom(TWO_PI);
    temp = newCircle(angle);
    circles.push_back(temp);
    
    for (int i = 0; i< circles.size(); i++){

        float distToCtr = ofDist(circles[i].x, circles[i].y, ctr.x, ctr.y);
        
        ofVec2f pos;
        pos.set(circles[i].x, circles[i].y);
        ofVec2f diff = pos - ctr;
        diff.normalize();
        
        ofVec2f outerCirclePoint = ofVec2f(ctr + diff * maxRad);
        float distToLimit = pos.distance (outerCirclePoint);
        

        if (distToCtr<maxRad){
            if(circles[i].growing){
                if(circles[i].r > distToLimit/2){
                    circles[i].growing = false;
                } else {
                    for (int j = 0; j< circles.size(); j++){
                        if(&circles[i] != &circles[j]){
                            float d = ofDist(circles[i].x,circles[i].y, circles[j].x, circles[j].y);
                            if(d -2 < circles[i].r + circles[j].r){
                                circles[i].growing = false;
                                break;
                            }
                        }
                    }
                }
            }
            circles[i].grow();
        }
        
        circles[i].draw();
//        ofSetColor(100);
        ofSetLineWidth(1);
        ofDrawLine(outerCirclePoint, ctr + diff * maxRad + diff * circles[i].r * 5);
//        ofDrawCircle(pos,2);
        ofSetColor(255);
        ofDrawCircle(outerCirclePoint,2);
        
        
        

        
    }
}

//--------------------------------------------------------------
circle ofApp::newCircle(float a){

//    float angle = ofRandom(TWO_PI);
    float angle = a;
    float x = ofGetWidth()/2 + sin(angle) * ofRandom(maxRad);
    float y = ofGetHeight()/2 + -cos(angle) * ofRandom(maxRad);
    
    bool valid = true;
    
    for (circle c : circles){
        float d = ofDist(x,y,c.x, c.y);
        
        if (d<c.r){
            valid = false;
            break;
        }
    }
    
    if (valid){
        circle temp;
        temp.setup(x, y);
        return temp;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
