#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(255);
    
    font.load("Helvetica-01.ttf", 8, true, true, true);
    
    // this creates an array of lines of poem
    movingYour.push_back("You");
    movingYour.push_back("are");
    movingYour.push_back("not");
    movingYour.push_back("were");
    movingYour.push_back("have");
    movingYour.push_back("did");
    movingYour.push_back("had");
    movingYour.push_back("will");
    movingYour.push_back("be");
    movingYour.push_back("can");
    movingYour.push_back("able");
    movingYour.push_back("cannot");
    movingYour.push_back("could");
    movingYour.push_back("were");
    movingYour.push_back("might");
    movingYour.push_back("ought");
    movingYour.push_back("must");
    movingYour.push_back("If");
    movingYour.push_back("Will");
    movingYour.push_back("you-r");
    
    for (int i=0; i<movingYour.size(); i++){
        moveableword temp;
        temp.word = movingYour[i];
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
    for (int i=0; i<movingYour.size(); i++){
        words[i].position.x = x + cos(TWO_PI/3*i +angle)*r;
        words[i].position.y = y + sin(TWO_PI/3*i +angle)*r;
        ofSetColor(0);
         font.drawString(words[i].word,words[i].position.x, words[i].position.y);
    }

}

//--------------------------------------------------------------
    
void ofApp::draw(){

    for (int j=0; j<250; j+=10){
        for (int i=0; i<100; i+=5){
            float t = ofGetElapsedTimef();
            
            
            float radius = ofMap(sin(t), -1, 1, 100, 400);
            
            
            ptx = xcenter + cos((t*i)/200)*radius*j/100*2;
            pty = ycenter + sin((t*i)/200)*radius*j/100*2;
            
            spin(ptx, pty, 100, sin(0.5*t+i)*2);
                font.drawString(words[i%20].word,words[i%20].position.x, words[i%20].position.y);
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
