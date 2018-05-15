#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    cam.initGrabber(640, 480);
    tracker.setup();
    
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
    cam.draw(0, 0);
    ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
    
    if(tracker.getFound()) {
        //        tracker.draw();
        ofPolyline face = tracker.getImageFeature(ofxFaceTracker::LEFT_EYE);
        ofRectangle faceBB = face.getBoundingBox();
        //mouthBB.scaleFromCenter(1.5);
        ofPixels facePixels = cam.getPixels();
        ofImage faceImage;
        faceImage.setFromPixels(facePixels);
        
        //        mouthPixels.draw(0, 0);
        //        mouth.draw();
        
        //get face
        ofPolyline eye = tracker.getImageFeature(ofxFaceTracker::LEFT_EYE);
        ofRectangle eyeBox = eye.getBoundingBox();
        //ofPoint eyeCenter = eyeBox.getCenter();
        
        
        facePixels.crop(faceBB.x, faceBB.y, faceBB.width, faceBB.height-(eyeBox.y+eyeBox.height/2));
        faceImage.draw(faceBB.x, faceBB.y);
        
        
        //mouthImage.draw(eyeCenter.x - mouthImage.getWidth() / 2, eyeCenter.y - mouthImage.getHeight() / 2);
        
        
        
        
        
        
        
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
