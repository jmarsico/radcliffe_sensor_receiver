#pragma once

#include "ofMain.h"
#include "ofxSerial.h"
#include "ofxNetwork.h"
#include "ofxOsc.h"
#include "ofxXmlSettings.h"

#define PORT 12345

class ofApp : public ofBaseApp{

	public:
    void setup();
    void update();
    
    bool autoDetect();
    
    ofx::IO::SerialDevice device;
    string targetDeviceName;
    
    ofxOscSender sender;
    ofxXmlSettings config;

		
};
