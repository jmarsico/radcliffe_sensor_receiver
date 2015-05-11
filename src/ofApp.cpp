#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //headless app needs to be restrained:
    ofSetFrameRate(30);
    
    //load config.xml
    if(!config.loadFile("config.xml"))
    {
        ofLog() << "Failed to load config.xml";
    }
    
    //this is the string we're looking for in serial devices
    
    //connect right off the bat
//    bool connected = autoDetect();
    
    string ipAddress = config.getValue("TARGETIP", "127.0.0.1");
    
    // open an outgoing connection to HOST:PORT
    sender.setup(ipAddress.c_str(), PORT);
    
    serial.listDevices();
    serial.setup("/dev/tty.usbmodem1411", 57600);
    //	serial.startContinuousRead();
    ofAddListener(serial.NEW_MESSAGE,this,&ofApp::onNewMessage);
    
    message = "";

}

//----------------------------------------------------------------
//----------------------------------------------------------------
//----------------------------------------------------------------
void ofApp::update(){
    serial.read();
    
}

void ofApp::onNewMessage(string & message)
{
    cout << "onNewMessage, message: " << message << "\n";
    
    vector<string> input = ofSplitString(message, ",");
    
    
    if(input.size() == 21)
    {
        
        for(int i = 0; i < 20; i++)
        {
            
        }
    }
}

    
void ofApp::sendToMaster(){

        
//        m.setAddress("/sensors");
    
    
     
//            m.addIntArg(buffer[i]);
        
        
    
//        sender.sendMessage(m);
//    }
    
}


//----------------------------------------------------------------
//----------------------------------------------------------------
//----------------------------------------------------------------
//bool ofApp::autoDetect(){
//    
//    ofx::IO::SerialDeviceInfo::DeviceList devicesInfo = ofx::IO::SerialDeviceUtils::listDevices();
//    
//    ofLogNotice("ofApp::autoDetect") << "Finding devices...";
//    
//    int deviceIndx = -1;
//    string deviceDescription;
//    bool success = false;
//    
//    for (std::size_t i = 0; i < devicesInfo.size(); ++i)
//    {
//        string devDesc = devicesInfo[i].getDescription();
//        ofLog() << devDesc;
//        if(devDesc.find(targetDeviceName) != string::npos)
//        {
//            deviceDescription = devDesc;
//            ofLogNotice("ofApp::autoDetect") << "detected device: " <<deviceDescription;
//            deviceIndx = i;
//        }
//    }
//    
//    //if we found a match
//    if(deviceIndx >= 0)
//    {
//        //tell us the device number and connect to it.
//        ofLogNotice("ofApp::autoDetect") << deviceDescription << " is device: " << deviceIndx;
//        success = device.setup(devicesInfo[deviceIndx], 9600);
//        
//    }else{
//        ofLogNotice("ofApp::autoDetect") << targetDeviceName << " not found";
//    }
//    
//    //if connection was successful, tell us and exit
//    if(success)
//    {
//        ofLogNotice("ofApp::autoDetect") << "successfully connected to " << deviceDescription;
//        return true;
//        
//    } else {
//        ofLogNotice("ofApp::autoDetect") << "failed to connect to " << targetDeviceName;
//        return false;
//    }
//}
