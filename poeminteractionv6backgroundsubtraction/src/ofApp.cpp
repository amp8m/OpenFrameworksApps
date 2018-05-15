#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grabber.setup(640,480);
    background.allocate(640,480, OF_IMAGE_COLOR);
    threshold.allocate(640,480, OF_IMAGE_COLOR);
    
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
            temp.originalPos = pos;
            temp.word = wordstemp[j];
            words.push_back(temp);
            
            // this is spacing the words out
            pos.x += font.getStringBoundingBox(wordstemp[j],0,0).width + 10;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){

    grabber.update();
    
    if (bSnapshot){

        background.setFromPixels(grabber.getPixels());
        background.update();

        bSnapshot = false;
    }
    
    for (int x = 0; x < 640; x++){
        for (int y = 0; y < 480; y++){
            // let's compare
            // pixel xy in video
            // vs pixel xy in background
            // and if abs(diff) > ...
            // do something.
            int camBrightness = grabber.getPixels().getColor(x,y).getBrightness();
            int backgroundBrightness = background.getColor(x,y).getBrightness();
            
            int diff = abs(camBrightness - backgroundBrightness);
            
            //threshold.setColor(x,y,ofColor(diff));
            if (diff > mouseX){
                threshold.setColor(x,y,ofColor(255));
            } else {
                threshold.setColor(x,y,ofColor(0));
            }
        }
    }
    threshold.update();
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){


}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' '){
        bSnapshot = true;
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
