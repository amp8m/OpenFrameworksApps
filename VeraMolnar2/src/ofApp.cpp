#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(255);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(0);
    ofSeedRandom(0);
    for (int x=0; x < 50; x++){
        for (int y =0; y < 50; y++){
            float randomAngle = ofRandom(-180,180);
    
            float flickerLine = ofMap(sin(ofGetElapsedTimef()-ofNoise(.01*x,.01*y)),-1,1,0,255);
            ofSetColor(flickerLine);
            
            ofPushMatrix();
            ofTranslate(x*20,y*20);
            ofRotateZ(randomAngle);
            
        
            ofDrawLine(0-10,0,0+10,0);
            
            
            ofPopMatrix();
        
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
