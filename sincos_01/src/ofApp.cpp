// Francisco Zamorano
// October 2017

#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0, 0, 0);
    
    res.set(ofGetWindowWidth(), ofGetWindowHeight());
    
    origin.set(res.x/2, res.y/2);
    ofSetCircleResolution(60);
    
    size = 5.5;
    nElements = 1280;
    ofSetVerticalSync(true);
    
    fbo.allocate(res.x, res.y);
    ofEnableDepthTest();

    bSave = false;
    snapCounter = 0;
    bSnapshot = false;
    
    ofEnableSmoothing();
    img.load("test.jpg");
    
}

//--------------------------------------------------------------
void ofApp::update(){
    angle = ofGetElapsedTimef() * 0.5;
    radius = 300;
    shader.load("shaders/basic.vert", "shaders/bloomFrag.frag");
//    shader.load("shaders/basic.vert", "shaders/barrelDistort.frag");
//    shader.load("shaders/basic.vert", "shaders/averaging.frag");

    
    fbo.begin();
    ofClear(0);
    
    float phase  = ofMap(mouseX, 0, res.x, 0, 1, true);
    float phaseY  = ofMap(mouseY, 0, res.y, 0, 1, true);
    ofColor b;
    b.setHsb(125, 255, 60);
    ofBackgroundGradient(ofColor(0,0,0), b, OF_GRADIENT_CIRCULAR);

    ofSetColor(255);
    for(int h=0; h<1;h++){
        for(int i=0; i<nElements;i++){
            float id;// = i;
            if(i>nElements/2){
                id = nElements-i;
            }else{
                id=i;
            }

            float x = origin.x + cos(TWO_PI/nElements*i) * ((h*10)+ radius * (cos(angle+id*phase)+1)/2);
            float y = origin.y + sin(TWO_PI/nElements*i) * ((h*10)+ radius * (sin(angle+id*phase)+1)/2);

            float osc = (cos(id*phase)+1)/2;
            c.setHsb(80 + osc*60 , 220 + osc*100, 150+125*osc);
            ofSetColor(c);
            ofDrawCircle(x,y,size * osc);
        }
    }
    
//    img.draw(0, 0, res.x, res.y);
    
    fbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
    if( bSave ){
        ofBeginSaveScreenAsPDF("screenshot-"+ofGetTimestampString()+".pdf", false);
    }
    
//    shader.begin();
    shader.setUniform2f("mouse", ofMap(mouseX,0,res.x, 0.0, 1.0), ofMap(mouseY,0,res.y,0.0,1.0));
    shader.setUniform2f("resolution", res.x, res.y);
    shader.setUniform1f("time", ofGetElapsedTimef());
    shader.setUniformTexture("tex", fbo.getTexture(), 0);
    shader.setUniform1f("mouseDown", ofGetMousePressed());
    fbo.draw(0,0);
//    shader.end();
    
    
    if (bSnapshot == true){
        // grab a rectangle at 200,200, width and height of 300,180
        img.grabScreen(0,0, res.x, res.y);
        
        string fileName = "snapshot_"+ofToString(10000+snapCounter)+".png";
        img.save(fileName, OF_IMAGE_QUALITY_BEST);
        snapString = "saved " + fileName;
        snapCounter++;
        bSnapshot = false;
    }
    
    if( bSave ){
        ofEndSaveScreenAsPDF();
        bSave = false;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
    case 's':
        bSave=true;
        break;
    case 'r':
        bSnapshot=true;
        cout<<bSnapshot<<endl;
        break;
        
        default:
            break;
    }
    
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
