#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    x = 100;
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

void ofApp::drawA(float x, float y, float width, float height){
        ofDrawLine(x,y+height,x+width/2,y);
        ofDrawLine(x+width/2,y,x+width, y+height);
        ofDrawLine(x,y+height/2,x+width,y+height/2);
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    
    float time = ofGetElapsedTimef();
    for(int i=0;i<255;i++) {
        float y = ofMap(sin(time*i*.05), -1,1, 0, ofGetHeight());
        for(int j=0;j<255;j++) {
            ofSetColor(i*10,j,mouseX/2);
            ofDrawCircle(i*20, y + j*.5, i*.07);
        }
    }
    // float y = ofMap(sin(time + (mouseY)*i), -1,1, 0, ofGetHeight());
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
