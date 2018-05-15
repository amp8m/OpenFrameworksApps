#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxFaceTracker.h"

class moveableword {
    
public:
    
    string word;
    ofPoint position;
    bool bPositive;
    float alpha = 1;
    
  
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        ofTrueTypeFont font;
    
        vector<string> movingYour;
        vector<string> positiveWords;
        vector<string> negativeWords; 
        vector <moveableword> words;
    
        ofVideoGrabber cam;
        ofxFaceTracker tracker;
    
    bool bDrawDebug;

    
    float xmovement = 500;
    float ymovement = 300;
    float xmovementTarget = 500;
    float ymovementTarget = 500;
    
    int faceLock = 0; 
    
 
};
