#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(255);
    
    for (int x=0; x < 50; x++){
        for (int y=0; y < 50; y++){
            elegantRandomValues[x][y] = ofRandom(-270, 270);
        }
    }

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(0);
    ofSeedRandom(0);
    // this is moving the lines at some random angle
    for (int x=0; x < 50; x++){
        for (int y =0; y < 50; y++){
// this is taken out because now there is an array for this
//            float randomAngle = ofRandom(-270,270);
           
    float randomAngle = elegantRandomValues[x][y];
           // this is making the lines pulse by changing their color from black to white at some random time
            float flickerLine = ofMap(sin(ofGetElapsedTimef()-ofNoise(.5*x,.5*y)),-1,1,0,255);
            ofSetColor(flickerLine);
    
            // this is starting some new thing when the lines are starting to get white-ish
            if (flickerLine > 245) elegantRandomValues[x][y] += ofRandom(-270,270);
    
            ofPushMatrix();
            // this is causing the lines to move vertically
            ofTranslate(0, ofMap(sin(ofGetElapsedTimef()-2 * ofNoise(.001*x,.001*y)),-1,1,0,-75));
//            ofTranslate(0, ofMap(sin(ofGetElapsedTimef()-2),-1,1,0,-150));

            // this is the spacing between the lines
            ofTranslate(x*15,y*15);
            ofRotateZ(randomAngle);
        
            
            ofDrawLine(0-10,0,0+10,0);
            
            
            ofPopMatrix();
        
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
