#pragma once

#include "ofMain.h"
#include "Direccion.hpp"

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
    string milisToText(float milis);
    string GetNextTime(int secAdded = 0);
    ofEasyCam cam;
    
    bool isRotating;
    bool isRotatingSideways;
    float prevCurveVal;
    bool goingUp;
    int prevSecond;
    float t;
    float millisAnimStarted;
    int prevDirection;
    int currDirection;
    
    
    Direccion direction[4];
    float angleX;
    float angleY;
    ofColor colores[5];
    ofColor currCol;
    ofColor prevCol;
    int lastRan;
    ofColor GetRndmColor();
    
    vector<string> movingYour;
};
