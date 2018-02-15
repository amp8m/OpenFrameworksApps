#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(100);
    
    for(int i=0; i<100; i++){
    x[i] = ofRandom(300,600);
    y[i] = ofRandom(300,600);
    velx[i] = ofRandom(-2,2);
    vely[i] = ofRandom(-2,2);
}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);
    ofSetColor(183, 123, 130);
    for(int i=0;i<100;i++){
        x[i] = x[i] + velx[i];
        y[i] = y[i] + vely[i];
        
        if(x[i] > ofGetWidth() || x[i] <0){
            velx[i] = velx[i] * -1;
        }
        if (y[i] > ofGetHeight() || y[i] <0){
            vely[i] = vely[i] * -1;
        }
    }
    
    for (int i=0; i < 100; i++){
        float radius = ofMap(sin(ofGetElapsedTimef()),-1,1,5,20);
    float flickerred = ofMap(sin(ofGetElapsedTimef()),-1,1,150,255);
    float flickerblue = ofMap(sin(ofGetElapsedTimef()),-1,1,60,180);
    float flickergreen =
        ofMap(sin(ofGetElapsedTimef()),-1,1,50,75);
    ofSetColor(flickerred,flickergreen, flickerblue);
    ofDrawCircle(x[i],y[i],radius);
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
