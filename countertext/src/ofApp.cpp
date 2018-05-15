#include "ofApp.h"
#include "Direccion.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    
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
    
    font.load("Helvetica-01.ttf", 50, true, true, true);
    prevSecond = ofGetSeconds();
    
    direction[0].rotationX = 90;
    direction[1].rotationY = 90;
    direction[2].rotationX = -90;
    direction[3].rotationY = -90;
    
    currDirection = 0;
    
    colores[0] = ofColor(253, 243, 235);
    colores[1] = ofColor(107, 171, 199);
    colores[2] = ofColor(239, 122, 52);
    colores[3] = ofColor(16, 115, 173);
    colores[4] = ofColor(233, 74, 77);
    colores[5] = ofColor(46, 46, 38);
    
    currCol = colores[0];
    prevCol = colores[1];
    
    GetRndmColor();
}

//--------------------------------------------------------------
void ofApp::update(){
    t = ofGetElapsedTimeMillis() * 0.001;
    
    if(prevSecond != ofGetSeconds()){
        // If is new second, then animation ended
        prevSecond = ofGetSeconds();
        isRotating = true; // So i know i have to change rotation in Draw
        millisAnimStarted = ofGetElapsedTimeMillis();
        
        prevDirection = currDirection; // Save previous direction
        GetRndmColor();
        do{
            currDirection = (int) (ofRandom(0, 4) ); // get a new random direction that is not same as previous one
        }while( currDirection == prevDirection );
        
        //cout << "prev dir " << prevDirection << " - cur dir " << currDirection << endl;
        //cout << "rot Y " << direction[currDirection].rotationY << " - rot X " << direction[currDirection].rotationX << endl;
    }
    
    // Calculate X and Y offsets according to new direction
    // this map handles rotation offset between each second
    // animLength is bottom map. It means the value will be changed when 'animLength' milliseconds have passed in current second
    float animLength = 400; // in miliseconds
    
    // millisAnimStarted+1000 is top map. Its the time destintation (one second from now)
    // Last parameter set to true means the map function will clamp these parameters
    animLength = 1000 - animLength;
    angleY = ofMap(ofGetElapsedTimeMillis(), millisAnimStarted + animLength, millisAnimStarted+1000, 0, direction[currDirection].rotationY, true);
    
    angleX = ofMap(ofGetElapsedTimeMillis(), millisAnimStarted + animLength, millisAnimStarted+1000, 0, direction[currDirection].rotationX, true);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(prevCol);
    
    cam.enableOrtho();
    cam.begin();
    
    
    // Set new rotation difference
    if(isRotating){
        ofRotateY(angleY);
        ofRotateX(angleX);
    }
    
    // Draw "Current" time
    ofPushMatrix();
    
    int currIndex = ((int)(ofGetElapsedTimef() - 0.4)) % movingYour.size();
    ofRectangle rect = font.getStringBoundingBox(movingYour[currIndex], 0, 0);
    
    ofTranslate(0, 0, 250);
    //Fondo del texto
    ofPushMatrix();
    ofSetColor(prevCol);
    ofTranslate(-rect.width/2, rect.height);
    ofDrawRectangle( rect );
    ofPopMatrix();
    ofColor txtCol = prevCol;
    txtCol.invert();
    ofSetColor( txtCol );
    font.drawString(movingYour[currIndex], -rect.width/2, 0);
    ofPopMatrix();
    
    // Rotate accordingly and draw "future" time
    int nextIndex = ((int)(ofGetElapsedTimef() - 0.4) + 1) % movingYour.size();
    ofPushMatrix();
    ofRotateY( -direction[currDirection].rotationY );
    ofRotateX( -direction[currDirection].rotationX );
    rect = font.getStringBoundingBox(movingYour[nextIndex], 0, 0);
    ofSetColor(0);
    
    
    ofTranslate(0, 0, 25);
    ofPushMatrix();
    ofSetColor(currCol);
    ofTranslate(-rect.width/2, rect.height);
    ofDrawRectangle( rect );
    ofPopMatrix();
    txtCol = currCol;
    txtCol.invert();
    ofSetColor(txtCol);
    font.drawString(movingYour[nextIndex], -rect.width/2, 0);
    ofPopMatrix();
    
    
    cam.end();
}

//--------------------------------------------------------------
ofColor ofApp::GetRndmColor(){
    int rand = 0;
    do{
        rand = ofRandom(0, (sizeof(colores)/sizeof(colores[0])) );
    }while(colores[rand] == currCol);
    
    prevCol = currCol;
    currCol = colores[rand];
    
    cout << "rand: " << rand << endl;
    return currCol;
}


//--------------------------------------------------------------
string ofApp::GetNextTime(int secAdded){
    int sec = ofGetSeconds() + secAdded;
    int min = ofGetMinutes();
    int hor = ofGetHours();
    if(sec > 59){
        min += 1;
        sec = 0;
    }
    if(min > 59){
        hor += 1;
        min = 0;
    }
    if(hor > 24){
        hor = 0;
    }
    return ofToString( hor, 2 ) + ":" + ofToString(min, 2) + ":" + ofToString(sec, 2);
}
//--------------------------------------------------------------
string ofApp::milisToText(float milis){
    
    int seconds = (int) (milis / 1000);
    int minutes = seconds / 60;
    int hours = minutes / 60;
    
    seconds %= 60;
    minutes %= 60;
    hours %= 12;
    
    string out = to_string( hours ) + ":" + to_string( minutes ) + ":" + to_string( seconds );
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
