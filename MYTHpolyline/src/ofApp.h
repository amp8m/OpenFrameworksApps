#pragma once

#include "ofMain.h"
#include "ofxHersheyFont.h"

#define SCENE_TWO_START 30

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        void scene1(float t);
        void scene2(float t);

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
		
        ofxHersheyFont hersheyFont;
    
        vector < string > linesOfTheFile;
    
    
};
