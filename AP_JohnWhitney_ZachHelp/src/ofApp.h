#pragma once

#include "ofMain.h"

#define SCENE_TWO_START 5

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        // these are methods we made to create scenes 
        void scene1(float twetold);
        void scene2(float twetold);

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
    
    

        int state;
    
    
		
};
