#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    int w = ofGetWidth();
    int h = ofGetHeight();
    
    int countSteps = 200;
    float totalWaves = 4;
    float time = ofGetElapsedTimef();
   
     ofBackground(255);
    
//    this makes the shape horizontal
//    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
//    ofRotate(90);
//    ofTranslate(-ofGetWidth()/2, -ofGetHeight() / 2);
    
    for (int j = 0; j < totalWaves; j++){
//    ofSetColor(240, 128, 128, time*20);
    ofSetColor(ofMap(sin(time), -1, 1, 199, 251), ofMap(sin(time*1.1), -1, 1, 30, 159), ofMap(sin(time*1.2), -1, 1, 17, 210), time*20);
        alpha += alphaChange;
        if (alpha >= 255){
            alphaChange = -1;
        } else if (alpha >= 0){
            alphaChange = 1;
        }
    ofBeginShape();
    
    //right side to center
    for (int i=0; i <countSteps; i++){
//        float x = (w / 2);
        float x = ofMap(j,0,totalWaves, (w / 2)*sin(time) , w + 200 * sin(.4* time + j)); x+= 200 * sin(time * (j+1)) + 100 * sin(i / 100);
        float y = ofMap(i, 0, countSteps, 0, h);
        float inputa = ofMap(i, 0, countSteps, 0, PI);
//        float amplitude = 50 * ofNoise (0.0025 * x, 0.0025 * y, .5 * time) + 20;
        float amplitude = 100 * ofNoise (x*.002,y*.002,time*.5)+10;
        ofVertex(x+amplitude * sin(inputa),y);
    }
     
    //left side to center
    for (int i=0; i < countSteps; i++){
//        for (int g=0; g < totalWaves; g++){
//        float x = (w / 2);
        float x = ofMap(j,0,totalWaves, (w / 2)*sin(time), w + 200 * sin(.4* time + j)); x+= 200 * sin(time * (j+1));
        float y = ofMap(i, 0, countSteps, h, 0);
        float inputb = ofMap(i, 0, countSteps, 0, PI);
//        float amplitude = 50 * ofNoise(0.0025 * x, .0025*y, 0.5 * time) + 20;
        float amplitude = 100 * ofNoise (x*.002,y*.002,time*.5)+10;
        ofVertex(x - amplitude * sin(inputb), y);
    }
//    }
    ofEndShape(OF_CLOSE);
    

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
