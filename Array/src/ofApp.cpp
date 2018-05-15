#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    x = 100;
    speed = 5;
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
    
//    for(int i=20;i<100;i++){
//        drawA(x,mouseY,i*2,i*4);
//    }
//    for(int i=0;i<100;i++){
//        drawA(i*mouseX,mouseY,i*2, 200);
//    }
    
//    float time = ofGetElapsedTimef();
    
    y = y + speed;
    if( y>ofGetHeight()-128 ||  y<0 )  {
        speed = -speed;
    }


    for(int i=0;i<255;i++) {
        for(int j=0;j<255;j++) {
            ofSetColor(i*10,j,mouseX/2);
            ofDrawCircle(i*20, y + j*10, i*.07);
        }
    }
    
//    y2 = y2 + speed;
//    if( y2>ofGetHeight()-128 ||  y2<0 )  {
//        speed = -speed;
//    }
//
//
//    for(int i=0;i<255;i++) {
//        for(int j=0;j<255;j++) {
//            ofSetColor(i*10,j,mouseX/2);
//            ofDrawCircle(i*20, y + j*.5, i*.07);
//        }
//    }
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
