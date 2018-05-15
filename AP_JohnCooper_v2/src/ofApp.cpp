#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

//    state = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
//    if (state == 0){
    int countSteps = 1000;
    
    //this is setting an array of the colors you will use
    ofColor myPalette[7];
    myPalette[0] = ofColor(250, 114, 210, 100);
    myPalette[1] = ofColor(219, 86, 138, 100);
    myPalette[2] = ofColor(199, 30, 17, 100);
    myPalette[3] = ofColor(211, 64, 148, 100);
    myPalette[4] = ofColor(250, 142, 132,100);
    myPalette[5] = ofColor(229, 115, 73,100);
    myPalette[6] = ofColor(251, 159, 167,100);
    myPalette[7] = ofColor(227, 138, 76,100);

    ofBackground(0);
    
    float time = ofGetElapsedTimef() * 0.1;
    float timeslow = ofGetElapsedTimef() * 0.001;
    float w = ofGetWidth();
    float h = ofGetHeight();
    
   // this is creating a for loop to duplicate the waves
    for (int j=0; j < 6; j++){
        
        ofSetColor( myPalette[j] );
        
        float frequency = ofMap(j,0,8,25.0,100.0);
        float phase = ofMap(j,0,8,3.0,20.0);
        float amplitude = ofMap(j,0,8,10.0,200.0);
        
        ofBeginShape();
        for (int i=0; i < countSteps; i++){
//            float frequency = ofMap(i,0,100,25.0,100.0);
            float phase = ofMap(i,0,100,5.0,8.0);
            float offset2 = ofMap(j,0,6,6,10);
//            float amplitude = ofMap(i,0,100,10.0,100.0);
            float x =(sin((i*0.01)/25.0+ phase + offset2*time) * 100);
            float y = ofMap(i,0,100,0,h*j+time*.5);
            
            // this is what is making each wave duplicate
//            x += (j+1) + sin(time);
            x += ofMap(sin(time),-1,1,0,w/2)+(sin(time)*i)+i;
//            ofDrawCircle(x,y,5);
            
            ofVertex(x,y);
        }
        
    // in the ofVertex, you are telling it to draw a shape from one direction to another, this is reversing the direction
        for (int i = countSteps-1; i >= 0; i--){
            float offset = sin(i/25.0)*ofMap(i,0,1000,130,150);
            float offset2 = ofMap(j,0,6,6,8);
//            float frequency = ofMap(i,0,100,25.00,100.0);
            float phase = ofMap(i,0,100,5.0,8.0);
//            float amplitude = ofMap(i,0,100,10.0,100.0);
            float x = (sin((i*0.01)/25.0+phase + time*offset2) * 100) + offset;
            float y = ofMap(i,0,100,0,h*j+time*.5);
//            float y = ofMap(i,0, countSteps, 0, ofGetHeight());
            
           // this is what is making each wave duplicate
//            x += ofMap(sin(j),-1,1,0,w) + sin(time)*w;

//            x += (j+1) + sin(time);
            x += ofMap(sin(time),-1,1,0,w/2)+(sin(time)*i)+i;
    //        ofDrawCircle(x,y,5);
            ofVertex(x,y);
    
        }
        ofEndShape();
    }
    
//    } else if (state == 1){
//        ofCircle(300,300,50);
//    } else {
//        ofLine(0,0,100,100);
//    }
    
    
//    if (ofGetFrameNum() % 120 == 0){
//        state = state+1;
//        if (state >= 3){
//            state = 0;
//        }
//    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

//    state = state+1;
//    if (state >= 3){
//        state = 0;
//    }
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
