#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    //ofSetFrameRate(1);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
//    float sineValue = sin(ofGetElapsedTimef());
//    int myColorValue = ofMap(sineValue,-1,1,0,255);
//    ofBackground(myColorValue);
//    //------------------
//    ofSetColor(ofRandom(0,255));
//    ofDrawRectangle(ofRandom(100,200),ofRandom(100,200),50,50);
//    //------------------
//    cout << ofGetElapsedTimef() << endl;
//    ofBackground(ofGetElapsedTimef()*10);
//    ofBackground(sin(ofGetElapsedTimef()));
    
    
    //ofSeedRandom(0);
//
//    ofSeedRandom(mouseX);
//
//    ofBackground(0);
//
//    ofSetColor(ofRandom(0,255),ofRandom(0,255), ofRandom(0,255));
//    ofDrawRectangle( ofRandom(100,200), ofRandom(100,200), 50, 50);
//
//    ofSetColor(ofRandom(0,255),ofRandom(0,255), ofRandom(0,255));
//    ofDrawRectangle( ofRandom(100,200), ofRandom(100,200), 50, 50);
//
//    ofSetColor(ofRandom(0,255),ofRandom(0,255), ofRandom(0,255));
//    ofDrawRectangle( ofRandom(100,200), ofRandom(100,200), 50, 50);
//
//    ofSetColor(ofRandom(0,255),ofRandom(0,255), ofRandom(0,255));
//    ofDrawRectangle( ofRandom(100,200), ofRandom(100,200), 50, 50);
//
//    ofSetColor(ofRandom(0,255),ofRandom(0,255), ofRandom(0,255));
//    ofDrawRectangle( ofRandom(100,200), ofRandom(100,200), 50, 50);
//
//    ofSetColor(ofRandom(0,255),ofRandom(0,255), ofRandom(0,255));
//    ofDrawRectangle( ofRandom(100,200), ofRandom(100,200), 50, 50);
//
//    ofSetColor(ofRandom(0,255),ofRandom(0,255), ofRandom(0,255));
//    ofDrawRectangle( ofRandom(100,200), ofRandom(100,200), 50, 50);
//
//    ofSetColor(ofRandom(0,255),ofRandom(0,255), ofRandom(0,255));
//    ofDrawRectangle( ofRandom(100,200), ofRandom(100,200), 50, 50);
//
//    ofSetColor(ofRandom(0,255),ofRandom(0,255), ofRandom(0,255));
//    ofDrawRectangle( ofRandom(100,200), ofRandom(100,200), 50, 50);
//
//    ofSetColor(ofRandom(0,255),ofRandom(0,255), ofRandom(0,255));
//    ofDrawRectangle( ofRandom(100,200), ofRandom(100,200), 50, 50);
    
    //cout << ofGetElapsedTimef() << endl;
    //cout << sin(ofGetElapsedTimef()) << endl;
    
//    float time = ofGetElapsedTimef();
//    float sinOfTime = sin(time);
//    float mappedSin = ofMap(sinOfTime, -1,1,0,1000 );
//    ofDrawCircle(mappedSin, 200, 20);
//
//    time = ofGetElapsedTimef() + 0.1;
//    sinOfTime = sin(time);
//    mappedSin = ofMap(sinOfTime, -1,1,0,1000 );
//    ofDrawCircle(mappedSin, 400, 20);
    
    ofBackground(0, 0, 0);
    
    ofSetColor(ofMap(mouseY, 0,ofGetHeight(),0,255));
    ofDrawCircle(400,400,  ofMap( mouseX, 0,  ofGetWidth(), 5,200)     );
    
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
