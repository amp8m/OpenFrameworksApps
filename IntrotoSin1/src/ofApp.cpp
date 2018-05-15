#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    float sinOfTime = (sin(ofGetElapsedTimef()+TWO_PI*.33));
    float sinOfTimeMapped = ofMap(sinOfTime,-1,1,50,300);
    ofSetColor(sinOfTimeMapped,0,0);
    ofDrawCircle(100,100, sinOfTimeMapped);
    
    float sinOfTime2 = (sin(ofGetElapsedTimef()+100));
    float sinOfTimeMapped2 = ofMap(sinOfTime2,-1,1,10,150);
    ofSetColor(sinOfTimeMapped2,0,0);
    ofDrawCircle(300,300, sinOfTimeMapped);
    
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
