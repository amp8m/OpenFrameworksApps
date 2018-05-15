#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(255);
    
    font.load("Helvetica-01.ttf", 20, true, true, true);
    
    positiveWords.push_back("able");
    positiveWords.push_back("will");
    positiveWords.push_back("can");
    
    for (int i=0; i<positiveWords.size(); i++){
        moveableword temp;
        temp.word = positiveWords[i];
        temp.position = ofPoint(400,400);
        words.push_back(temp);
    
    }
}
    
//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------

void ofApp::spin(float x, float y, float r, float angle){

    ofPoint position = ofPoint(x,y);
    for (int i=0; i<positiveWords.size(); i++){
        words[i].position.x = x + cos(TWO_PI/3*i +angle)*r;
        words[i].position.y = y + sin(TWO_PI/3*i +angle)*r;
        ofSetColor(0);
         font.drawString(words[i].word,words[i].position.x, words[i].position.y);
    }

}

//--------------------------------------------------------------
    
void ofApp::draw(){

    for (int j=0; j<280; j+=8){
        for (int i=0; i<400; i+=10){
            float t = ofGetElapsedTimef();
            
            
            float radius = ofMap(sin(t*i/100+j/100), -1, 1, 100, 400);
            
            
            ptx = xcenter + cos(t*j/200)*radius*i/100*2;
            
            pty = ycenter + sin(t*j/200)*radius*i/100*2;
            
            spin(ptx, pty, 10, sin(t+i)*8);
                font.drawString(words[i%3].word,words[i%3].position.x, words[i%3].position.y);
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
