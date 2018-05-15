#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cam.initGrabber(320, 240);
    tracker.setup();
    
    bDrawDebug = false;
    
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
    positiveWords.push_back("can.");
    positiveWords.push_back("You");
    
    
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
    
    for (int i = 0; i < words.size(); i++){
        words[i].bPositive = false;
        for (int j=0; j<positiveWords.size(); j++){
            if (words[i].word == positiveWords[j]){
                words[i].bPositive = true;
            }
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
    
    float width = ofGetWidth();
    float height = ofGetHeight();
    
    if (bDrawDebug){
        
        ofSetColor(255);
        // if we are drawing debug, draw the video and face tracker
        cam.draw(0,0);
        tracker.draw();
        
        ofSetColor(0);
    }
    
    
    float time = ofGetElapsedTimef();
    float slider = ofMap(mouseX,0,ofGetWidth(),1,0);
    float breathe = ofMap(sin(time),-1,1,0,255);
    
    xmovement = xmovement*0.9 + xmovementTarget*0.1;
    ymovement = ymovement*0.9 + ymovementTarget*0.1;
    
    int count = 10;
    if(tracker.getFound()) {
        xmovementTarget = 10;
        ymovementTarget = 10;
        ofSetColor(breathe);
        count = 1;
    } else {
        xmovementTarget = 500;
        ymovementTarget = 300;
    }
    
    if (xmovement < 11) {
        faceLock++;
    
    }else{
        faceLock = 0;
    }
    
    //cout << faceLock << endl;
    
    if (faceLock > 200) {
        for(int i=0; i<words.size(); i++){
            if (words[i].bPositive == false){
                words[i].alpha = .90*words[i].alpha + 0.1*0;
            }
        }
    } else {
        for(int i=0; i<words.size(); i++){
            if (words[i].bPositive == false){
                words[i].alpha = .99*words[i].alpha + 0.01*1;
            }
        }
    }
    
    if (faceLock > 400) {
        for(int i=0; i<words.size(); i++){
            if (words[i].bPositive == true){
                words[i].alpha = .99*words[i].alpha + 0.01*0;
            }
        }
    } else {
        for(int i=0; i<words.size(); i++){
            if (words[i].bPositive == true){
                words[i].alpha = .99*words[i].alpha + 0.01*1;
            }
        }
    }
    
    
    
    for (int j = 0; j < count; j++) {
        for(int i=0; i<words.size(); i++){
            ofSetColor(0,0,0, words[i].alpha * 255);
    //            font.drawString(words[i].word,
    //                            words[i].position.x
    //                                + ofSignedNoise(
    //                                    words[i].position.x,
    //                                    words[i].position.y*.1, time * .4) * xmovement,
    //                            words[i].position.y
    //                                + ofSignedNoise(
    //                                    words[i].position.x*0.1,
    //                                    words[i].position.y*0.1, time*.4) * ymovement);
            float xRadius = xmovement / 2;
            float yRadius = ymovement / 2;
            float angle = (2 * ofNoise(i, j) + 5) * time + i;
          
            
            if (tracker.getFound()) {
                font.drawString(words[i].word, words[i].position.x + xRadius * cos(angle), words[i].position.y + yRadius * sin(angle));
            } else {
                float numwordsonline = 10;
                font.drawString(words[i].word, 200 * cos(angle) + width / 2, 200 * sin(angle) + height / 2);
                ofVec3f dir = ofVec2f(ofRandom(-1, 1), ofRandom(-1, 1));
                for (int k = 0; k < numwordsonline; k++){
                    font.drawString(words[i].word, (200 * cos(angle) + width / 2) + 100*k*dir.x, (200 * sin(angle) + height / 2)+100*k*dir.y);
                }
                
                
            }
        
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    
    if (key == 'd'){
        bDrawDebug = !bDrawDebug;
    }
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
