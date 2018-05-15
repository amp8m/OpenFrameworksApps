#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    hersheyFont.setColor(ofColor(0));
  
//    ofBuffer buffer = ofBufferFromFile("movingyour");
//    for (auto line : buffer.getLines()){
//        if (line.size() > 0){
//            linesOfTheFile.push_back(line);
//            cout << line << endl;
//        }
//    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    
//    for (int i=0; i < linesOfTheFile.size(); i++){
//        int whichLine = ofGetSeconds()* 2 % linesOfTheFile.size(); // this makes each line fall every second
//        string message = linesOfTheFile[whichLine];
//        //    for (int i=0; i<pts.size(); i++){
//        string temp = "";
//        temp += message [i % message.size()];
//        //        font.drawString(temp, pts[i].x, pts[i].y);
//        //    }
//
    float t = ofGetElapsedTimef();
    
    if (t < SCENE_TWO_START){
        scene1(t);
    } else {
        scene2(t - SCENE_TWO_START);
    }
}


//--------------------------------------------------------------
void ofApp::scene1(float t){

    // this starts at the same random each time
    ofSeedRandom(0);
    
    float w = ofGetWidth();
    float h = ofGetHeight();
    
    string m = "MYTH";
    //    hersheyFont.draw(m,ofGetWidth()/2,ofGetHeight()/2,4,true);
    ofPath p = hersheyFont.getPath(m,ofGetWidth()/2,ofGetHeight()/2,12);
    //    p.draw();
    vector < ofPolyline > outlines = p.getOutline();
    
    // this is a bunch of code to center the ofPath
    float xMin = outlines[0].getVertices()[0].x;
    float xMax = outlines[0].getVertices()[0].x;
    float yMin = outlines[0].getVertices()[0].y;
    float yMax = outlines[0].getVertices()[0].y;
    for (int i = 0; i < outlines.size(); i++) {
        for (int j = 0; j < outlines[i].getVertices().size(); j++) {
            ofPoint pt = outlines[i].getVertices()[j];
            if (pt.x < xMin) xMin = pt.x;
            if (pt.x > xMax) xMax = pt.x;
            if (pt.y < yMin) yMin = pt.y;
            if (pt.y > yMax) yMax = pt.y;
        }
    }
    ofPoint center = ofPoint((xMax-xMin)/2 + (xMin - w / 2),(yMin - h / 2) - (yMin - yMax));
    
    for (int i=0; i<outlines.size(); i++){
        //      outlines[i].draw();
        ofPolyline newPoly = outlines[i].getResampledBySpacing(30);
        vector<ofPoint> points = newPoly.getVertices();
        newPoly.getVertices().size();
//        cout << newPoly.getVertices().size() << "," << i <<  endl;

        for (int j=0; j < points.size(); j++){
            if (i == 0 || i == 3 || i == 5 ) {
            hersheyFont.draw("cannot", (points[j] - center).x, (points[j] - center).y,.35, true);
            }
            if (i == 1 || i == 2 || i == 6 || i == 10 || i == 7) {
            hersheyFont.draw("not", (points[j] - center).x, (points[j] - center).y, .35, true);
            }
            if ((i == 4 && (j < 10)) || i == 8 || i == 9) {
                hersheyFont.draw("ought", (points[j] - center).x, (points[j] - center).y, .35, true);
            }
            if (i == 4 && j > 10) {
                hersheyFont.draw("not", (points[j] - center).x, (points[j] - center).y, .35, true);
//            } else {
//            hersheyFont.draw("if", (points[j] - center).x, (points[j] - center).y, 0.5, true);
        }

            
            
        }
        
    }
    
}

//--------------------------------------------------------------
void ofApp::scene2(float t){

    // this starts at the same random each time
    ofSeedRandom(0);
    
    float w = ofGetWidth();
    float h = ofGetHeight();
    
    string s = "=>";
    //    hersheyFont.draw(s,ofGetWidth()/2,ofGetHeight()/2,4,true);
    ofPath p = hersheyFont.getPath(s,ofGetWidth()/2,ofGetHeight()/2,12);
    //    p.draw();
    vector < ofPolyline > outlines = p.getOutline();
    
    // this is a bunch of code to center the ofPath
    float xMin = outlines[0].getVertices()[0].x;
    float xMax = outlines[0].getVertices()[0].x;
    float yMin = outlines[0].getVertices()[0].y;
    float yMax = outlines[0].getVertices()[0].y;
    for (int i = 0; i < outlines.size(); i++) {
        for (int j = 0; j < outlines[i].getVertices().size(); j++) {
            ofPoint pt = outlines[i].getVertices()[j];
            if (pt.x < xMin) xMin = pt.x;
            if (pt.x > xMax) xMax = pt.x;
            if (pt.y < yMin) yMin = pt.y;
            if (pt.y > yMax) yMax = pt.y;
        }
    }
    ofPoint center = ofPoint((xMax-xMin)/2 + (xMin - w / 2),(yMin - h / 2) - (yMin - yMax));
    
    for (int i=0; i<outlines.size(); i++){
        //      outlines[i].draw();
        ofPolyline newPoly = outlines[2].getResampledBySpacing(20);
        vector<ofPoint> points = newPoly.getVertices();
        cout << newPoly.getVertices().size() << "," << i <<  endl;
        
        for (int j=0; j < points.size(); j++){
            //            ofDrawCircle((points[j] - center).x, (points[j] - center).y, 2);
            if (ofRandom(1) < 0.5) {
                hersheyFont.draw("test", (points[j] - center).x, (points[j] - center).y, 0.5, true);
            } else {
                hersheyFont.draw("if", (points[j] - center).x, (points[j] - center).y, 0.5, true);
            }
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
