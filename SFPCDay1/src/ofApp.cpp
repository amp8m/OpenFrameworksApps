#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
// Name, need to finish S
ofBackground(0,0,0);
ofSetColor(255,255,255);
ofDrawLine(50,100,75,5);
    ofDrawLine(75,5,100,100);
    ofDrawLine(50,50,100,50);
    ofDrawLine(120,100,120,5);
    ofDrawLine(120,5,165,5);
    ofDrawLine(120,100,165,100);
    ofDrawLine(165,100,165,50);
    ofDrawLine(135,50,165,50);
    ofDrawLine(185,100,185,5);
    ofDrawLine(185,5,225,100);
    ofDrawLine(225,100,225,5);
    ofDrawLine(245,100,245,5);
    ofDrawLine(245,100,290,100);
    ofDrawLine(245,50,275,50);
    ofDrawLine(245,5,290,5);
    ofDrawLine(310,100,350,100);
    ofDrawLine(350,100,350,50);
     ofDrawLine(310,50,350,50);
     ofDrawLine(310,50,310,5);
     ofDrawLine(310,5,350,5);
// First E
    ofDrawLine(75,300,75,200);
    ofDrawLine(75,300,110,300);
    ofDrawLine(75,200,110,200);
    ofDrawLine(75,250,95,250);
    ofDrawLine(80,300,80,200);
    ofDrawLine(80,300,115,300);
    ofDrawLine(80,200,115,200);
    ofDrawLine(80,250,100,250);
    // Next E
    ofDrawLine(125,300,125,200);
    ofDrawLine(125,300,160,300);
    ofDrawLine(125,200,160,200);
    ofDrawLine(125,250,145,250);
    ofDrawLine(130,300,130,200);
    ofDrawLine(130,300,170,300);
    ofDrawLine(130,200,170,200);
    ofDrawLine(130,250,155,250);
    // creating a variable to draw E
    float x = 75;
    float y = 400;
    float width = mouseX;
    float height = mouseY;
    // draw E
    ofDrawLine(x,y,x,y+height);
    ofDrawLine(x,y,x+width,y);
    ofDrawLine(x,y+height,x+width,y+height);
    ofDrawLine(x,y+height*.5,x+width*.5,y+height*.5);
    // draw another E, can't call it float though
     x = 275;
     y = 400;
     width = 50;
     height = 100;
    ofDrawLine(x,y,x,y+height);
    ofDrawLine(x,y,x+width,y);
    ofDrawLine(x,y+height,x+width,y+height);
    ofDrawLine(x,y+height*.5,x+width*.5,y+height*.5);
    // Scale the E to half size
    x = 350;
    y = 400;
    width = 50;
    height = 100;
    ofDrawLine(x,y,x,y+height*.5);
    ofDrawLine(x,y,x+width*.5,y);
    ofDrawLine(x,y+height*.5,x+width*.5,y+height*.5);
    ofDrawLine(x,y+height*.25,x+width*.25,y+height*.25);
    // Scale the E to quarter size
    x = 400;
    y = 400;
    width = 50;
    height = 100;
    ofDrawLine(x,y,x,y+height*.25);
    ofDrawLine(x,y,x+width*.25,y);
    ofDrawLine(x,y+height*.25,x+width*.25,y+height*.25);
    ofDrawLine(x,y+height*.125,x+width*.125,y+height*.125);
    // Scale the E to half the size of quarter size
    x = 435;
    y = 400;
    width = 50;
    height = 100;
    ofDrawLine(x,y,x,y+height*.125);
    ofDrawLine(x,y,x+width*.125,y);
    ofDrawLine(x,y+height*.125,x+width*.125,y+height*.125);
    ofDrawLine(x,y+height*.0625,x+width*.0625,y+height*.0625);
    // Scale the E to quarter the size of quarter size
    x = 460;
    y = 400;
    width = 50;
    height = 100;
    ofDrawLine(x,y,x,y+height*.0625);
    ofDrawLine(x,y,x+width*.0625,y);
    ofDrawLine(x,y+height*.0625,x+width*.0625,y+height*.0625);
    ofDrawLine(x,y+height*.03125,x+width*.03125,y+height*.03125);
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
