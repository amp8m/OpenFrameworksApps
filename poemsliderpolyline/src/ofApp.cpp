#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("Helvetica-01.ttf", 10, true, true, true);
     hersheyFont.setColor(ofColor(0));
    
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
    
    // this splits the lines of the poem into words
    for (int i=0; i<movingYour.size(); i++){
        vector<string> wordstemp = ofSplitString(movingYour[i]," ");
        ofPoint pos = ofPoint(100, i*20+50);
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
    
    
    string m = "MYTH";
    ofPath p = hersheyFont.getPath(m,ofGetWidth()/2,ofGetHeight()/2,12);
    vector < ofPolyline > outlines = p.getOutline();
    
    words[67].target = ofPoint(400,100);
    words[43].target = ofPoint(200,200);
    
    
    for (int i=0; i<outlines.size(); i++){
        ofPolyline newPoly = outlines[i].getResampledBySpacing(30);
        vector<ofPoint> points = newPoly.getVertices();
        newPoly.getVertices().size();
        
        words[67].target = ofPoint(points.x, points.y);
        words[43].target = ofPoint(points.x, points.y);
        
//        for (int j=0; j < points.size(); j++){
//            if (i == 0 || i == 3 || i == 5 ) {
//                hersheyFont.draw("cannot", (points[j]).x, (points[j]).y,.35, true);
//            }
//            if (i == 1 || i == 2 || i == 6 || i == 10 || i == 7) {
//                hersheyFont.draw("not", (points[j]).x, (points[j]).y, .35, true);
//            }
//            if ((i == 4 && (j < 10)) || i == 8 || i == 9) {
//                hersheyFont.draw("ought", (points[j]).x, (points[j]).y, .35, true);
//            }
//            if (i == 4 && j > 10) {
//                hersheyFont.draw("not", (points[j]).x, (points[j]).y, .35, true);
//            }
//        }
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);
    ofSetColor(0);
    //    for(int i=0; i<movingYour.size(); i++ ){
    //        font.drawString( movingYour[i], 100, i*20);
    //
    //    }
    
    float time = ofGetElapsedTimef();
    float slider = ofMap(mouseX,0,ofGetWidth(),0,1);
    
    for(int i=0; i<words.size(); i++){
        
        ofPoint pos = (1-slider) * words[i].position + slider*words[i].target;
        font.drawString(words[i].word, pos.x, pos.y);
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
