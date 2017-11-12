#pragma once

#include "ofMain.h"
#include "ofxJSONElement.h"
#include "ofxOsc.h"
#define HOST "255.255.255.255"
#define PORT 2017
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
    
    ofxJSONElement Input;
    ofxOscSender Sender;
    ofxOscMessage time,weather,rain,clouds,temp,wind;
    int kind[38];

};
