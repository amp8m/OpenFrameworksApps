#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    font.load("Helvetica-01.ttf", 10, true, true, true);
    
    // this creates an array of lines of poem
    movingYour.push_back("You are");
    movingYour.push_back("You are not");
    movingYour.push_back("You were");
    movingYour.push_back("You were not");
    movingYour.push_back("You have, you did");
    movingYour.push_back("You have not, you did not");
    movingYour.push_back("You had");
    movingYour.push_back("You had not");
    movingYour.push_back("You will");
    movingYour.push_back("You will be");
    movingYour.push_back("You will not");
    movingYour.push_back("You will not be");
    movingYour.push_back("You can. You are able");
    movingYour.push_back("You cannot. You are not able");
    movingYour.push_back("You could not. You were");
    movingYour.push_back("not able");
    movingYour.push_back("You might");
    movingYour.push_back("You might not");
    movingYour.push_back("You ought");
    movingYour.push_back("You ought not");
    movingYour.push_back("You must");
    movingYour.push_back("If you can. If you are able");
    movingYour.push_back("Will you-r");
    
    positiveWords.push_back("able");
    positiveWords.push_back("will");
    positiveWords.push_back("can");

    // this splits the lines of the poem into words
    for (int i=0; i<movingYour.size(); i++){
        vector<string> wordstemp = ofSplitString(movingYour[i]," ");
        ofPoint pos = ofPoint(ofGetWidth()/2, i*20+50);
        for (int j=0; j<wordstemp.size(); j++){
            
            // this is creating an object called temp of the type moveableword
            moveableword temp;
            temp.position = pos;
            temp.word = wordstemp[j];
            words.push_back(temp);
            
            // this is spacing the words out
            pos.x += font.getStringBoundingBox(wordstemp[j],0,0).width + 10;
        }
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);
    ofSetColor(0);
    
    float time = ofGetElapsedTimef();
    float slider = ofMap(mouseX,0,ofGetWidth(),1,0);
//    float angle = time * 10;
//    float radius = 10;

    
        for(int i=0; i<words.size(); i++){
            
//            font.drawString(words[i].word, words[i].position.x + (radius+i) + sin(angle), words[i].position.y + (radius+i) + sin(angle));
            
            
            font.drawString(words[i].word, words[i].position.x + ofSignedNoise(words[i].position.x,words[i].position.y*.1, time * .4) * 500, words[i].position.y + ofSignedNoise(words[i].position.x*0.1, words[i].position.y*0.1, time*.4) * 300);
            
//            font.drawString(words[i].word, words[i].position.x + ofSignedNoise(words[i].position.x*0.1,words[i].position.y*0.1, time) * 100 * slider, words[i].position.y + ofSignedNoise(words[i].position.x*0.1, words[i].position.y*0.1, time+1000) * 100 * slider);

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
