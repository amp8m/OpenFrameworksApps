#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------

void ofApp::tri(float x, float y, float r, float angle){
    
    ofPoint pt[3];
    for (int i=0; i<3; i++){
        pt[i].x = x + cos(TWO_PI/3*i +angle)*r;
        pt[i].y = y + sin(TWO_PI/3*i +angle)*r;
        ofSetColor(255);
    }
    ofDrawTriangle(pt[0], pt[1], pt[2]);
}

//--------------------------------------------------------------

void ofApp::draw(){

    float t = ofGetElapsedTimef();
    tri(200,200, 100, t);
    
    
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
