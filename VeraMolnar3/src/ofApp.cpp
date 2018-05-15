#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    }

//--------------------------------------------------------------
void ofApp::update(){

}
void ofApp:: veraSquares(float x, float y, float width, float height){
    
    //this changes the square sizes according to mouseX
    stepsize = abs(mouseX/10);
    for (int i=0; i < 20; i++){
        ofPoint a(x+i*stepsize,y+i*stepsize);
        ofPoint b(x-i*stepsize+width,y+i*stepsize);
        ofPoint c(x-i*stepsize+width,y-i*stepsize+height);
        ofPoint d(x+i*stepsize,y-i*stepsize+height);

//    stepsize = 20;
//        for (int i=0; i < 20; i++){
//            ofPoint a(x-i*stepsize,y+i*stepsize);
//            ofPoint b(x+i*stepsize+width,y+i*stepsize);
//            ofPoint c(x+i*stepsize+width,y-i*stepsize+height);
//            ofPoint d(x-i*stepsize,y-i*stepsize+height);

        ofDrawLine (a,b);
        ofDrawLine (b,c);
        ofDrawLine (c,d);
        ofDrawLine (a,d);
    }
    
            stepsize = 5;
                for (int i=0; i < 20; i++){
//                    ofPoint a(x-i*stepsize,y+i*stepsize);
//                    ofPoint b(x+i*stepsize+width,y+i*stepsize);
//                    ofPoint c(x+i*stepsize+width,y-i*stepsize+height);
//                    ofPoint d(x-i*stepsize,y-i*stepsize+height);
                    ofPoint a(x, y);
                    ofPoint b(x + width, y);
                    ofPoint c(x + width, y + height);
                    ofPoint d(x, y + height);
                    
                    // Grow
                    a.x += stepsize * i *-1;
                    b.x += stepsize * i;
                    c.x += stepsize * i;
                    d.x += stepsize * i *-1;
                    
                    // Grow Randomly
                    float topRand = ofRandom(-30,30);
                    float bottRand = ofRandom(-30,30);
                    a.y += topRand + i *10*-1;
                    b.y += topRand+ i *10*-1;
                    c.y += bottRand+ i *10 ;
                    d.y += bottRand+ i *10;
        
        ofDrawLine (a,b);
        ofDrawLine (b,c);
        ofDrawLine (c,d);
        ofDrawLine (a,d);
    }
    
        
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSeedRandom(0);
//   // EXPERIMENT 1 - these are squares within squares
    ofBackground(255);
    ofSetColor(0);
    float width = 300;
    float height = 300;
    // this centers the squares in the middle of the page
    float xposition = ofGetWidth()/2 - width/2;
    float yposition = ofGetHeight()/2 - height/2;
    veraSquares(xposition,yposition,width,height);

////     EXPERIMENT 2
//    ofBackground(255);
//    ofSetColor(0);
//    float width = ofNoise(mouseX)*100;
//    float height = 300;
//    float xposition = ofGetWidth()/2 - width/2;
//    float yposition = ofGetHeight()/2 - height/2;
//    veraSquares(xposition,yposition,width,height);
   
    ////     EXPERIMENT 3
//        ofBackground(255);
//        ofSetColor(0);
//        float width = 300;
//        float height = ofNoise(mouseY)*100;
//        float xposition = ofGetWidth()/2 - width/2;
//        float yposition = ofGetHeight()/2 - height/2;
//        veraSquares(xposition,yposition,width,height);
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
