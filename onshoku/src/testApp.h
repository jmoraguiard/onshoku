#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"

#include "ofxOpenCv.h"
#include "TileMatrix.h"
#include "ColorRecognizer.h"
#include "boxAlign.h"



// uncomment this to use a live camera otherwise, we'll use a movie file 
#define _USE_LIVE_VIDEO  




class testApp : public ofBaseApp{

public:

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);

		
	#ifdef _USE_LIVE_VIDEO
		ofVideoGrabber 		vidGrabber;
	#else
		ofVideoPlayer 		vidPlayer;
	#endif 

	
	ofImage             tileMatrixImage;

	ofxCvColorImage		colorImg;
    ofxCvColorImage		inputImage;
    ofxCvColorImage 	analyzedImageMatrix; 
	ofxCvColorImage 	analyzedImageReference; 
    ofxCvColorImage     digitalImage;
    ofxCvColorImage 	outputImage;

	ofTrueTypeFont		font;
	ofTrueTypeFont		info;

	ofTexture		texScreen;

	int hue;
	int sat;
	int val;

	unsigned char *pixels;

	int colors[5][3];
	int isTheColor;

	TileMatrix tileMatrix;
	ColorRecognizer colorRecognizer;

    CBoxAligner         boxInputMatrix; 
	CBoxAligner         boxInputReference; 
    CBoxAligner         boxOutput; 
	
	char reportStr[1024]; 

private:



};

#endif
