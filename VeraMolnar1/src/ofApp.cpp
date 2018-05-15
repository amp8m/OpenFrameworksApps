#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(255);
    ofSetColor(0);
    for(int i=0; i<30;i++){
        RandomValues[i] = ofRandom(100,500);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

//    ofDrawBox(400,400,mouseX,ofRandom(10));
    
// THIS IS THE CODE TO CREATE A SQUARE THAT CHANGES AT DIFF POINTS
//    ofSeedRandom(mouseX*1000);
//
//    ofPoint a(200,200);
//    ofPoint b(400,200);
//    ofPoint c(400,400);
//    ofPoint d(200,400);
//
//    a.x = a.x + ofRandom(-mouseY,mouseY);
//    b.x = b.x + ofRandom(-mouseY,mouseY);
//    c.x = c.x + ofRandom(-mouseY,mouseY);
//    d.x = d.x + ofRandom(-mouseY,mouseY);
//
//
//    ofDrawLine(a,b);
//    ofDrawLine(b,c);
//    ofDrawLine(c,d);
//    ofDrawLine(d,a);
    
// EXPERIMENT 1
//    ofNoFill();
//    for (int i=0; i < 30; i++){
//        ofDrawRectangle(100+i*20,100+i*20, RandomValues[i], mouseX);
    
// EXPERIMENT 2
//    ofNoFill();
//    for (int i=0; i < 30; i++){
//    ofDrawRectangle(RandomValues[i],RandomValues[i], i*50, ofGetElapsedTimef()*100);
    
//    }

    
   
      
    }
//}

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
