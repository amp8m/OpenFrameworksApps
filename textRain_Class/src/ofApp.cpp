#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    // this calls the camera and B&W image next to it
    camera.setup(640,480);
    thresholdImg.allocate(640,480, OF_IMAGE_COLOR);
    
    font.load("Helvetica-01.ttf", 30);
    
    // this creates growable arrays called Points
    // the i controls the spacing between the letters
    for (int i=0; i < 20; i++){
        ofPoint temp;
        temp.set(ofMap(i, 0, 20, 0, 640),0); // in Zach's example this is random
        pts.push_back(temp); // this grows the array
    }
    
    bDebug = false;
    
    // this adds a string of text from a txt file
    ofBuffer buffer = ofBufferFromFile("movingyour");
    for (auto line : buffer.getLines()){
        if (line.size() > 0){
        linesOfTheFile.push_back(line);
        cout << line << endl;
        }
    }

    countParticles = 100;
    for (int i=0; i < countParticles; i++){ // this is creating particles
        ParticleVec3 temp; // announcing ParticleVec3 with name "temp"
        // need to tell it where it is, where it starts
        temp.position = ofVec3f(ofRandom(camera.getWidth()),0);
        particles.push_back(temp); // this grows the array
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){

    camera.update();
    
   // this is telling the B&W Threshold Image how to be based on brightness
    for(int x = 0; x < 640; x++){
        for (int y = 0; y < 480; y++){
            ofColor pixel = camera.getPixels().getColor(x,y);
            if (pixel.getBrightness() > 127){
                thresholdImg.setColor(x,y,ofColor(255));
            } else {
        thresholdImg.setColor(x,y,ofColor(0));
        }
    }
}
thresholdImg.update();

// this is getting the color of whatever is below the point
for (int i =0; i< pts.size(); i++){
    ofColor pixel = thresholdImg.getColor(pts[i].x, ofClamp(pts[i].y + 1,0,480 - 1));
    
   // if the pixels are light, then fall
    if (pixel.getBrightness()> 127){
        pts[i].y += 3 * ofNoise(pts[i].x); // this makes letters fall at different speeds
//        pts[i].y += 20 + sin(pts[i].x);
//        pts[i].y += 5;
    } else {
        int yPos = pts[i].y;
        int xPos = pts[i].x;
        
      // if the pixels are light, then stop falling
        for (int y = yPos; y>= 0; y --){
            ofColor otherPixel = thresholdImg.getColor(xPos, y);
            if (otherPixel.getBrightness()>127){
                pts[i].y = y;
                break;
            }
        }
    }
    
    // if pixel has fallen, restart it and send it back up to the top
        if (pts[i].y > 480) {
        pts[i].y = 0;
            
        }
    }

    for (int i = 0; i < countParticles; i++){ // this is the for loop to add forces to the particles
        particles[i].addForce(ofVec3f(0,.1)); // this is adding a force to the particles
        ofColor pixel = thresholdImg.getColor(particles[i].position.x, ofClamp(particles[i].position.y + 1,0,480 - 1)); // this is getting the color of whatever is below the point
        // if a pixel is dark, stop it
        if (pixel.getBrightness() < 127){
             particles[i].velocity = ofVec3f(0, 0);
             particles[i].acceleration = ofVec3f(0, 0);
             
          // tells you how far away the particle is from a white pixel
            int countAway = 0;
             for (int y = particles[i].position.y; y >= 0; y--){ // subtraction for loop
                 ofColor otherPixel = thresholdImg.getColor(particles[i].position.x, y); // why no clamp here?
                 if (otherPixel.getBrightness()>127) break;
                 countAway++;
             }
            
            particles[i].addForce(ofVec3f(0, -countAway / 5));
             
         }
        if (particles[i].position.y > camera.getHeight()){ // if particles fall below the height
            particles[i].position.y = 0; // restart them
            particles[i].velocity = ofVec3f(0, 0); // restart the gravity
            particles[i].acceleration = ofVec3f(0, 0); // restart the gravity
        }
        particles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255);
    camera.draw(0,0);
    if (bDebug){
        thresholdImg.draw(640,0);
    }
    
    ofSetColor(0,0,0);
    
    int whichLine = ofGetSeconds()* 2 % linesOfTheFile.size(); // this makes each line fall every second
    string message = linesOfTheFile[whichLine];
    for (int i=0; i<pts.size(); i++){
        string temp = "";
        temp += message [i % message.size()];
        font.drawString(temp, pts[i].x, pts[i].y);
    }

    for (int i =0; i < countParticles; i++){
        particles[i].draw(); // drew the particles from setup
        int whichLine = ofGetSeconds()* 2 % linesOfTheFile.size(); // this makes each line fall every second
        string message = linesOfTheFile[whichLine];
        string temp = "";
        temp += message [i % message.size()];
        font.drawString(temp, pts[i].x, pts[i].y);
        
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' '){
        bDebug = !bDebug;
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
