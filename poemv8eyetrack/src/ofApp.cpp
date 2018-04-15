#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cam.initGrabber(640, 480);
    tracker.setup();
    
    font.load("Helvetica-01.ttf", 15, true, true, true);
    
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
    
    negativeWords.push_back("not");
    negativeWords.push_back("ought");
    negativeWords.push_back("cannot");
    negativeWords.push_back("if");

    
    // this splits the lines of the poem into words
    for (int i=0; i<movingYour.size(); i++){
        vector<string> wordstemp = ofSplitString(movingYour[i]," ");
        ofPoint pos = ofPoint(ofGetWidth()/2, i*25+50);
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

    cam.update();
    if(cam.isFrameNew()) {
        tracker.update(ofxCv::toCv(cam));
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);
    ofSetColor(0);
    
    float time = ofGetElapsedTimef();
    float slider = ofMap(mouseX,0,ofGetWidth(),1,0);
    float xmovement = 500;
    float xmovementTarget;
    float ymovement = 300;
    float breathe = ofMap(sin(time),-1,1,0,255);
    
    xmovement = xmovement*0.9 + xmovementTarget*0.1;
    
    for(int i=0; i<words.size(); i++){
        
        if(tracker.getFound()) {
            xmovementTarget = 10;
            font.drawString(words[i].word,words[i].position.x + ofSignedNoise(words[i].position.x,words[i].position.y*.1, time * .4) * xmovementTarget, words[i].position.y + ofSignedNoise(words[i].position.x*0.1, words[i].position.y*0.1, time* .4));
            ofSetColor(breathe);
        } else {
            xmovementTarget = 500;
            font.drawString(words[i].word,words[i].position.x + ofSignedNoise(words[i].position.x,words[i].position.y*.1, time * .4) * xmovement, words[i].position.y + ofSignedNoise(words[i].position.x*0.1, words[i].position.y*0.1, time*.4) * ymovement);
            
        }
        
    
    }
    // trying to make negative words disappear if someone is still
    if(tracker.getFound() && time >10) {
        for(int i=0; i<negativeWords.size(); i++){
            ofSetColor(255,255,255,0);
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
