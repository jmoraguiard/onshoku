#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){
	
	
	/* 
	ofxXmlSettings XML; 
	
	 
	//config 
	//we load our settings file
	//if it doesn't exist we can still make one
	//by hitting the 's' key
	string file = "q.xml"; 
	
	if (XML.loadFile(file)) {
		
		//sprintf(message, "mySettings.xml loaded!"); 
		printf("hola");
		
	} else {
		printf("hola 2");
		//message = "unable to load myConfig.xml check data/ folder";
	} 
	
	//read the colors from XML
	//if the settings file doesn't exist we assigns default values (170, 190, 240)
	int appWidth	= XML.getValue("APP:SIZE:X", 800);
	int appHeight	= XML.getValue("APP:SIZE:Y", 600);
	int appMode 	= XML.getValue("APP:MODE", 0); 
	*/ 
	
	int appWidth	= 1024;
	int appHeight	= 768;
	int appMode = OF_WINDOW; 
	 

    ofAppGlutWindow window;
	ofSetupOpenGL(&window, appWidth, appHeight, appMode);			// <-------- setup the GL context
	//ofSetLogLevel(OF_LOG_VERBOSE);	
	ofSetLogLevel(OF_LOG_WARNING);
	//ofSetBackgroundAuto(false);
	
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new testApp());

}
