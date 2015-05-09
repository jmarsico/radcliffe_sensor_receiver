#pragma once

#include "ofMain.h"
#include "ofxSerial.h"
#include "ofxNetwork.h"
#include "ofxOsc.h"

#define HOST "localhost"
#define PORT 12345

class ofApp : public ofBaseApp{

	public:
    void setup();
    void update();
    
    bool autoDetect();
    
    ofx::IO::SerialDevice device;
    string targetDeviceName;
//    ofxUDPManager udpConnection;
    
    ofxOscSender sender;

		
};
