#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cam.initGrabber(320, 240);
    tracker.setup();
    
    bDrawDebug = false;
    
    ofSetFullscreen(true);
    
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
    
    negativeWords.push_back("not");
    negativeWords.push_back("ought");
    negativeWords.push_back("cannot");
    negativeWords.push_back("if");

    
    // this splits the lines of the poem into words
    for (int i=0; i<movingYour.size(); i++){
        vector<string> wordstemp = ofSplitString(movingYour[i]," ");
//        ofPoint pos = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
                ofPoint pos = ofPoint(ofGetWidth()/2, i*25+150);
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

void ofApp::spin(float x, float y, float r, float angle){
    
    ofPoint position = ofPoint(x,y);
    for (int i=0; i<positiveWords.size(); i++){
        ofSetColor(0);
        font.drawString(positiveWords[i],x + cos(TWO_PI/3*i +angle)*r, y + sin(TWO_PI/3*i +angle)*r);
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
    
    int count = 10;
    float time = ofGetElapsedTimef();
   
    xmovement = xmovement*0.95 + xmovementTarget*0.05;
    ymovement = ymovement*0.95 + ymovementTarget*0.05;
    
    if(tracker.getFound()) {
        xmovementTarget = 2;
        ymovementTarget = 2;
    } else {
        xmovementTarget = 500;
        ymovementTarget = 300;
 
    }
    
    if (xmovement < 11) {
        faceLock++;
    } else {
        faceLock = 0;
    }
    
    if (faceLock > 500 && faceLock < 600) {
        for(int i=0; i<words.size(); i++){
            if (words[i].bPositive == false){
                words[i].alpha = .95*words[i].alpha;
            }
        }
        if (!tracker.getFound()) {
            faceLock = 0;
            for (int i=0; i<words.size(); i++){
                words[i].alpha = 1;
            }
        }
    }
    
    else if (faceLock >= 600) {
        for (int j=0; j<100; j+=40){
            for (int i=0; i<400; i+=25){
                
                float t = ofGetElapsedTimef();
                
                float radius = ofMap(sin(t), -1, 1, 100, 400);
                
                float ptx = width / 2 + cos(t*i/200)*radius*j/100*2;
                
                float pty = height / 2 + sin(t*i/200)*radius*j/100*2;
                
                spin(ptx, pty, 100, sin(0.5*t+i)*2);
            }
        }
        for(int i=0; i<words.size(); i++){
            if (words[i].bPositive == true){
                words[i].alpha = 0;
            }
        }
        if (!tracker.getFound()) {
            faceLock = 0;
            for (int i=0; i<words.size(); i++){
                words[i].alpha = 1;
            }
        }
    }
    
    for(int i=0; i<words.size(); i++){
        ofSetColor(0,0,0, words[i].alpha * 255);
            font.drawString(words[i].word,words[i].position.x + sin(time+i) * xmovement + xspin, words[i].position.y + cos(time+i) * ymovement + yspin);

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

//    ofSetWindowShape(w, h);
//    // preserve Width
//    w = newW;
//    h = w / desiredAspect;
//
//    // preserve Height
//    h = newH;
//    w = h * desiredAspect;
//
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
