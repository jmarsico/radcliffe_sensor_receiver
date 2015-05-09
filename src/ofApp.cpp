#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //headless app needs to be restrained:
    ofSetFrameRate(30);
    
    //this is the string we're looking for in serial devices
    targetDeviceName = "Arduino";
    
    //connect right off the bat
    bool connected = autoDetect();
    
    // open an outgoing connection to HOST:PORT
    sender.setup(HOST, PORT);
    
//    udpConnection.Create();
//    udpConnection.Connect("127.0.0.1",12345);
//    udpConnection.SetNonBlocking(true);
}

//----------------------------------------------------------------
//----------------------------------------------------------------
//----------------------------------------------------------------
void ofApp::update(){
    
    ofxOscMessage m;
    ofxOscMessage error;
    std::size_t sz;
    uint8_t buffer[1024];
    
    if(!device.isOpen())
    {
        error.setAddress("/noArduino");
        sender.sendMessage(error);
        autoDetect();
        ofSleepMillis(5000);
    }
    
    // The serial device can throw exeptions.
    try
    {
        // Read all bytes from the device;
        while (device.available() > 0)
        {
            sz = device.readBytes(buffer, 1024);
            ofLog() << "number of bytes received: " << sz;
            
            for (int i = 0; i < sz; ++i)
            {
                std::cout << buffer[i];
        
            }
        }
    }
    
    //if serial connection fails, start looking for new serial connection
    catch (const std::exception& exc)
    {
        
        ofLogError("ofApp::serialReceiver") << exc.what();
        error.setAddress("/error");
        sender.sendMessage(error);
        autoDetect();
        ofSleepMillis(5000);
    }
    sz = 20;
    
    for(int i = 0; i < sz; i++)
    {
        buffer[i] = (uint8_t)ofRandom(2);
    }
    
    //if you receive all twenty values, send it to the mothership
    if(sz == 20)
    {
        m.setAddress("/sensors");
        for(int i = 0; i < sz; i++)
        {
            m.addIntArg((int)buffer[i]);
        }
        sender.sendMessage(m);
    }
    
}


//----------------------------------------------------------------
//----------------------------------------------------------------
//----------------------------------------------------------------
bool ofApp::autoDetect(){
    
    ofx::IO::SerialDeviceInfo::DeviceList devicesInfo = ofx::IO::SerialDeviceUtils::listDevices();
    
    ofLogNotice("ofApp::autoDetect") << "Finding devices...";
    
    int deviceIndx = -1;
    string deviceDescription;
    bool success = false;
    
    for (std::size_t i = 0; i < devicesInfo.size(); ++i)
    {
        string devDesc = devicesInfo[i].getDescription();
        ofLog() << devDesc;
        if(devDesc.find(targetDeviceName) != string::npos)
        {
            deviceDescription = devDesc;
            ofLogNotice("ofApp::autoDetect") << "detected device: " <<deviceDescription;
            deviceIndx = i;
        }
    }
    
    //if we found a match
    if(deviceIndx >= 0)
    {
        //tell us the device number and connect to it.
        ofLogNotice("ofApp::autoDetect") << deviceDescription << " is device: " << deviceIndx;
        success = device.setup(devicesInfo[deviceIndx], 9600);
        
    }else{
        ofLogNotice("ofApp::autoDetect") << targetDeviceName << " not found";
    }
    
    //if connection was successful, tell us and exit
    if(success)
    {
        ofLogNotice("ofApp::autoDetect") << "successfully connected to " << deviceDescription;
        return true;
        
    } else {
        ofLogNotice("ofApp::autoDetect") << "failed to connect to " << targetDeviceName;
        return false;
    }
}
