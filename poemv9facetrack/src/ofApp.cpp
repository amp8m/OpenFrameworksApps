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

    singleWords.push_back("You");
    singleWords.push_back("are");
    singleWords.push_back("not");
    singleWords.push_back("were");
    singleWords.push_back("have");
    singleWords.push_back("did");
    singleWords.push_back("had");
    singleWords.push_back("will");
    singleWords.push_back("be");
    singleWords.push_back("can");
    singleWords.push_back("able");
    singleWords.push_back("cannot");
    singleWords.push_back("could");
    singleWords.push_back("were");
    singleWords.push_back("might");
    singleWords.push_back("ought");
    singleWords.push_back("must");
    singleWords.push_back("If");
    singleWords.push_back("Will");
    singleWords.push_back("you-r");
    
    
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

void ofApp::spin(float x, float y, float r, float angle){
    
//    ofPoint position = ofPoint(x,y);
//    for (int i=0; i<singleWords.size(); i++){
//        words[i].position.x = x + cos(TWO_PI/3*i +angle)*r;
//        words[i].position.y = y + sin(TWO_PI/3*i +angle)*r;
//        ofSetColor(0);
//        font.drawString(words[i].word,words[i].position.x, words[i].position.y);
//    }
    
    ofPoint position = ofPoint(x,y);
    for (int i=0; i<singleWords.size(); i++){
//        words[i].position.x = x;
//        words[i].position.y = y;
        ofSetColor(0);
        font.drawString(words[i].word,words[i].position.x + cos(TWO_PI/3*i +angle)*r, words[i].position.y + sin(TWO_PI/3*i +angle)*r);
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);
    ofSetColor(0);
    
    
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
    
    if(tracker.getFound()) {
        xmovementTarget = 10;
        ymovementTarget = 10;
        ofSetColor(breathe);
    } else {
        
        for (int j=0; j<10; j+=10){
            for (int i=0; i<20; i+=5){
                float t = ofGetElapsedTimef();
                
                float radius = ofMap(sin(t), -1, 1, 100, 400);
                
                ptx = xcenter + cos((t*i)/200)*radius*j/100*2;
                pty = ycenter + sin((t*i)/200)*radius*j/100*2;
                
                spin(ptx, pty, 100, sin(0.5*t+i)*2);
//                font.drawString(words[i%20].word,words[i%20].position.x, words[i%20].position.y);
                font.drawString(singleWords[i%20],words[i%20].position.x, words[i%20].position.y);
            }
        }
        
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
    
    
    
    for(int i=0; i<words.size(); i++){
        ofSetColor(0,0,0, words[i].alpha * 255);
            font.drawString(words[i].word,words[i].position.x + ofSignedNoise(words[i].position.x,words[i].position.y*.1, time * .4) * xmovement, words[i].position.y + ofSignedNoise(words[i].position.x*0.1, words[i].position.y*0.1, time*.4) * ymovement);
    
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
