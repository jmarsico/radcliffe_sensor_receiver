
//Jakob Marsico
//copyright Ultra Low Res Studio 2015
//Radcliffe Landscape


#include "ofAppNoWindow.h"
#include "ofApp.h"


int main()
{
    ofAppNoWindow window;
    
    ofSetupOpenGL(&window, 250, 50, OF_WINDOW);
    ofRunApp(new ofApp());
}
