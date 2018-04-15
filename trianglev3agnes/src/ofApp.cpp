#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
     ofBackground(255);

}

//--------------------------------------------------------------
void ofApp::tri(float x, float y, float r, float angle){

    ofPoint pt[3];
    for (int i=0; i<3; i++){
        pt[i].x = x + cos(TWO_PI/3*i +angle)*r;
        pt[i].y = y + sin(TWO_PI/3*i +angle)*r;
        ofSetColor(0);
    }
    ofDrawTriangle(pt[0], pt[1], pt[2]);
}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    //float sint = ofMap(sin)
    
    for (int j=0; j<280; j+=8){
        for (int i=0; i<400; i+=10){
            float t = ofGetElapsedTimef();
            float radius = ofMap(sin(t*i/100+j/100), -1, 1, 100, 400);
            ptx = xcenter + cos(t*j/200)*radius*i/100*2;
            pty = ycenter + sin(t*j/200)*radius*i/100*2;
            tri(ptx, pty, 10, sin(t+i)*8);
        }
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
