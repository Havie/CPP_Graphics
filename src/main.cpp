#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( )
{
	//default way
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
	//Tetzlaf way
	//ofGLWindowSettings glSettings;
	//glSettings.setSize(1024, 768);
	//glSettings.windowMode = OF_WINDOW;
	//glSettings.setGLVersion(4, 1);
	//ofCreateWindow(glSettings);
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
