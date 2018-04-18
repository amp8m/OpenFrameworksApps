#include "ofApp.h"
#include "data.h"

//--------------------------------------------------------------
void ofApp::setup(){


    
    //----------------------------------------------------------------
    // the data is stored in a big flat array, let's copy it into something more managable
    // don't have to touch this :)
    
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 24; j++){
            float x = data3d[ i * 24 * 3  + j * 3 + 0 ];
            float y = data3d[ i * 24 * 3  + j * 3 + 1 ];
            float z = data3d[ i * 24 * 3  + j * 3 + 2 ];
            frames[i][j].set(x,y,z);
        }
    }
    
//    for (int i = 0; i < 30; i++){
//        for (int j = 0; j < 24; j++){
//            float x = data2d[ i * 24 * 2  + j * 2 + 0 ];
//            float y = data2d[ i * 24 * 2  + j * 2 + 1 ];
//            frames2d[i][j].set(x,y);
//        }
//    }
    //----------------------------------------------------------------

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

//    ofColor myPalette[4];
//    myPalette[0]= (203,6,37);
//    myPallete[1]=
//    myPalette[2]=
//    myPalette[3]=
    
    
    ofBackground(0);
    
    

    
    // you don't have to touch this either:)
    //----------------------------- copy data into array
    ofPoint data3d[24];
//    ofPoint data2d[24];

    cam.begin();
    cam.enableOrtho();
    for (int j=0; j < 30; j++){
        int frameNumber = (int)(j + ofGetFrameNum()*0.4) % 30;
//    int frameNumber =(int)(ofGetFrameNum()*0.4) % 30;
    for (int i = 0; i < 24; i++){
        data3d[i] = frames[ frameNumber][i];
//        data2d[i] = frames2d[frameNumber][i];
    }
    
    // end do not touch
    
    ofPoint spacing = .5 * ofPoint(ofMap(j,0,30,-ofGetWidth()/2,ofGetWidth()/2),0,0);
//    //----------------------------- 3d

    float time = ofGetElapsedTimef();

    for (int i = 0; i < 24; i++){
        ofSetColor(200+j*2,5+j*4, 35+j*2);
        ofDrawSphere(data3d[i] - spacing*j, 10); // this draws a circle at a specific point

        
    }

//
    

    
    
    }
    
    cam.end();
//
//    for (int i = 0; i < 24; i++){
//        //ofCircle(data2d[i], 4);
//    }
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
