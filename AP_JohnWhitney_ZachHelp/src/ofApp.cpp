#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    state = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float t = ofGetElapsedTimef();
    
    if (t < SCENE_TWO_START){
        scene1(t);
    } else {
        scene2(t - SCENE_TWO_START);
    }
    
//    if (state == 0){
//        scene1();
//    } else if (state == 1){
//        scene2();
//    } else {
//        ofDrawLine(0,0,100,100);
//    }
//
    
//     every 120 frames, go back to 0
//        if (ofGetFrameNum() % 120 == 0){
//            state = state+1;
//            if (state >= 3){
//                state = 0;
//            }
//        }
}

//--------------------------------------------------------------
void ofApp::scene1(float twetold){

    int countSteps = 500;
    
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
    
    // we replaced ofGetElapsedTimef() with twetold
    float time = twetold; // * 0.05;
    float timeslow = twetold * 0.001;
    float w = ofGetWidth();
    float h = ofGetHeight();
    
    // this is creating a for loop to duplicate the waves
    for (int j=0; j < 6; j++){
        
        ofSetColor( myPalette[j] );
        
        float frequency = ofMap(j,0,8,25.0,100.0);
        float phase = ofMap(j,0,8,3.0,20.0);
        float amplitude = ofMap(j,0,8,10.0,200.0);
        
        float scalespeed = ofMap(j,0,6,1,1.2);
        
        float scalefreq = ofMap(sin(time+j),-1,1,0.001,0.002);
        float scalefreq2 = ofMap(sin(time+j*0.8 + 2),-1,1,0.003,0.0);
        
        ofBeginShape();
        for (int i=0; i < countSteps; i++){
            //            float frequency = ofMap(i,0,100,25.0,100.0);
            float phase = ofMap(i,0,100,5.0,8.0);
            float offset2 = ofMap(j,0,6,6,10);
            //            float amplitude = ofMap(i,0,100,10.0,100.0);
            float x = j*100 + (sin(i*0.01 + time*0 + j)*sin(time+j*0.6 + 1) * 100) ;
            //            float y = ofMap(i,0,100,0,h*j+time*.5);
            float y = ofMap(i,0, countSteps, 0, ofGetHeight());
            
            
            // this is what is making each wave duplicate
            //            x += (j+1) + sin(time);
            //x += ofMap(sin(time),-1,1,0,w/2)+(sin(time)*i)+i;
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
            float x = j*100+ (sin(time + j)* 150 + 150) + (sin(i*0.01 + time*0 + j)*sin(time+j) * 100);
            //            float y = ofMap(i,0,100,0,h*j+time*.5);
            float y = ofMap(i,0, countSteps, 0, ofGetHeight());
            
            //float y = ofMap(i,0,100,0,h*j+.5);
            
            // this is what is making each wave duplicate
            //            x += ofMap(sin(j),-1,1,0,w) + sin(time)*w;
            
            //            x += (j+1) + sin(time);
            // x += ofMap(sin(time),-1,1,0,w/2)+(sin(time)*i)+i;
            //        ofDrawCircle(x,y,5);
            ofVertex(x,y);
            
        }
        ofEndShape();
    }
    
}
//--------------------------------------------------------------
void ofApp::scene2(float twetold){
    
    
    ofDrawCircle(300,300, twetold *10);
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
