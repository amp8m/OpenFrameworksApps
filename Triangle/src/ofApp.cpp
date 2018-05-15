#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//x=100,
//    y=100;
//    width = 100;
//    height = 100;
}

//--------------------------------------------------------------
void ofApp::update(){

}

void ofApp::drawPattern(float x, float y, float width, float height){
        ofDrawTriangle(x,y,x+width/2,y+height/2,x,y+height);
        ofDrawTriangle(x,y,x+width/2,y+height/2,x+width,y);
        ofDrawTriangle(x+width,y,x+width,y+height,x+width/2, y+height/2);
        ofDrawTriangle(x+width/2, y+height/2, x+width, y+height, x, y+height);
}

void ofApp::drawRotatedSquare(float x, float y, float width, float height){
    ofDrawTriangle(x,y+height/4,x-width/4,y,x,y-height/4);
    ofDrawTriangle(x,y+height/4,x+width/4,y,x,y-height/4);
    
}

void ofApp::drawRose(float x, float y, float width, float height){
    ofSetColor(183,123,130);
    drawRotatedSquare(x*1.5,y*1.5,width*2.75,height*2.75);
    ofFill();
    ofSetColor(183,123,130);
    drawPattern(x,y,width,height);
    ofNoFill();
    ofSetColor(154,10,53);
    drawPattern(x,y,width,height);
    ofFill();
    ofSetColor(43,64,35);
    drawRotatedSquare(x,y,width,height);
    ofDrawRectangle(145,145,10,10);
    drawRotatedSquare(x+width,y,width,height);
    drawRotatedSquare(x+width,y+height,width,height);
    drawRotatedSquare(x,y+height,width, height);

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
        ofFill();
//    for(int i=0;i>150 && i<255;i++){
//        for(int j=0;j>50 && j<125;j++){
//            for( int k=0;k>75 && k<150;k++){
//        ofSetColor(i,j,k);
//        }
//        }
//    }
    
    drawRose(100, 100, 100, 100);

//    ofDrawTriangle(100,100,100,200,150,150);
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
