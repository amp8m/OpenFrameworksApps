#pragma once

#include "ofMain.h"
#include <fstream>
#include "ParticleVec3.h"

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
		
    ofVideoGrabber camera;
    
    ofImage thresholdImg;
    
    ofTrueTypeFont font;
    
    vector < ofPoint > pts;
    vector < ParticleVec3 > particles;
    
    bool bDebug; 
    
    int height = ofGetHeight();
    
    vector < string > linesOfTheFile;
    
    int countParticles;
};
