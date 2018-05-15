#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

     font.load("helvetica.otf", 100, true, true, true);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    
    ofEnableDepthTest();
    
    //ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    //cam.enableOrtho();
    
    cam.begin();
    ofSetColor(255);
    
    font.drawString("gimme",0,0);
    
    ofRectangle bounds = font.getStringBoundingBox("gimme", 300,300);
    font.getStringBoundingBox("gimme", 300,300);
    bounds.getWidth();
    bounds.getHeight();
    cout << bounds.getWidth() << endl;
    cout << bounds.getHeight() << endl;
    
    ofPushMatrix();
    ofRotateY(90);
    ofSetColor(255,0,0);
    font.drawString("gimme",0,0);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(0,-10,-350);
    ofRotateY(90);
    ofRotateZ(270);
    ofSetColor(0,0,255);
    font.drawString("gimme",0,0);
    ofPopMatrix();

    
    cam.end();
    
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
