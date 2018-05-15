#pragma once

#include "ofMain.h"

class moveableword {
    
public:
    
    string word;
    ofPoint position;
    ofPoint originalPos;
    ofPoint target;
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
    vector <moveableword> words;
    
    ofVideoGrabber grabber;
    ofImage background;
    ofImage threshold;
    bool bSnapshot;


    
};
