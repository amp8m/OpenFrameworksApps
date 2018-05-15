#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground (0);
    
    float x = 0;
    float y = 0;
    float angle_start = 0.01 * mouseY;
    float angle_end = 0.01 * mouseX;
    float r1 = 250;
    float r2 = 300;
    ofBeginShape();
    // inner circle
    for (int i = 0; i <= 100; i++) {
        float angle = ofMap(i, 0, 100, angle_start, angle_end);
        ofVertex(r1 * cos(angle), r1 * sin(angle));
    }
    for (int i = 0; i <= 100; i++) {
        float angle = ofMap(i, 0, 100, angle_end, angle_start);
        ofVertex(r2 * cos(angle), r2 * sin(angle));
    }
    ofEndShape(OF_CLOSE);
    
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
