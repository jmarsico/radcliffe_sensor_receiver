#pragma once

#include "ofMain.h"
#include "ofxNetwork.h"
#include "ofxOsc.h"
#include "ofxXmlSettings.h"
#include "ofxSimpleSerial.h"

#define PORT 12345

class ofApp : public ofBaseApp{

	public:
    void setup();
    void update();
    
//    bool autoDetect();
//    void sendToMaster();
    void		onNewMessage(string & message);
    
    ofxSimpleSerial	serial;
    

    
    ofxOscSender sender;
    ofxXmlSettings config;
    
    string		message;
    
    
    
		
};
