#include "testApp.h"

int camWidth = 640; 
int camHeight = 320; 

int imgWidth = 320;
int imgHeight = 240; 


/* 
 * TODO: sequenciador, audio, video  
 * TOFIX: colores 
 *
 *
 */
 

//--------------------------------------------------------------
void testApp::setup() {

	
	ofSetLogLevel(OF_LOG_VERBOSE); 
	//vidGrabber.listDevices(); 
	//vidGrabber.videoSettings(); 
	ofSetLogLevel(OF_LOG_WARNING); 
	//vidGrabber.setDeviceID(4);
	

	info.loadFont("./fonts/verdana.ttf", 20); 
	
		
	#ifdef _USE_LIVE_VIDEO
		vidGrabber.setVerbose(true); 
		vidGrabber.initGrabber(camWidth, camHeight); 
	#else
		vidPlayer.loadMovie("colores2.mov"); 
		vidPlayer.play();
	#endif 
		

	//box para el warping 
	boxInputMatrix.setup( 15, 50, imgWidth, imgHeight); 
	boxInputReference.setup( 400, 50, 50, 100); 
	boxOutput.setup( 675, 50, imgWidth, imgHeight);

	//imagenes 
    inputImage.allocate(imgWidth, imgHeight);
	analyzedImageMatrix.allocate(imgWidth, imgHeight); 
	analyzedImageReference.allocate(imgWidth, imgHeight);

	digitalImage.allocate(imgWidth, imgHeight);
	outputImage.allocate(imgWidth, imgHeight);

	pixels = analyzedImageMatrix.getPixels();

	tileMatrix = TileMatrix(pixels, colors);
	colorRecognizer = ColorRecognizer(pixels, colors);

	tileMatrixImage.loadImage("tileMatrix.jpg");
    digitalImage.setFromPixels(tileMatrixImage.getPixels(), imgWidth, imgHeight);

}

//--------------------------------------------------------------
void testApp::update(){
	ofBackground(100,100,100);

    bool bNewFrame = false;
		
	#ifdef _USE_LIVE_VIDEO
		vidGrabber.grabFrame();
		bNewFrame = vidGrabber.isFrameNew();
	#else
		vidPlayer.idleMovie();
		bNewFrame = vidPlayer.isFrameNew();
	#endif 
		
	if (bNewFrame) {		
			
		#ifdef _USE_LIVE_VIDEO
				inputImage.setFromPixels(vidGrabber.getPixels(), camWidth, camHeight); 
		#else 
				inputImage.setFromPixels(vidPlayer.getPixels(), camWidth, camHe); 
		#endif 
		

        ofPoint dstPts[4] = {
            ofPoint(0, imgHeight, 0),
            ofPoint(imgWidth, imgHeight, 0),
            ofPoint(imgWidth, 0, 0),
            ofPoint(0, 0, 0)
        };

        analyzedImageMatrix.warpIntoMe(inputImage, boxInputMatrix.fHandles, dstPts ); 
		analyzedImageReference.warpIntoMe(inputImage, boxInputMatrix.fHandles, dstPts ); 
		outputImage.warpIntoMe(digitalImage, boxOutput.fHandles, dstPts );

		pixels = analyzedImageMatrix.getPixels();

		tileMatrix.update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(0xffffff);

	//video input 
	sprintf(reportStr, "Input Image");
	ofDrawBitmapString(reportStr, 15, 305);
	
	#ifdef _USE_LIVE_VIDEO
		vidGrabber.draw(15, 50, imgWidth, imgHeight); 
	#else
		vidPlayer.draw(15, 50, imgWidth, imgHeight); 
	#endif 
		

	//analyzed image 
	sprintf(reportStr, "Analyzed Image");
	ofDrawBitmapString(reportStr, 345, 305);
	ofPushMatrix();
    ofTranslate(345, 50, 0);
	ofScale(0.5, 0.5, 1);
    tileMatrix.draw();
    ofPopMatrix();

    ofSetColor(0xffffff);

	
    //DIGITAL IMAGE 
	sprintf(reportStr, "Digital Image");
	ofDrawBitmapString(reportStr, 675, 305);
    tileMatrixImage.draw(675, 50, imgWidth, imgHeight));

	
    //OUTPUT IMAGE 
	sprintf(reportStr, "Output Image");
	ofDrawBitmapString(reportStr, 675, 575); 
    outputImage.draw(675, 320, imgWidth, imgHeight));  //preview 
    outputImage.draw(1024, 0); //output 

	
	//recuadritos para diferenciar zonas 
    ofSetColor(0x000000);
	ofNoFill();
    ofRect(15, 50, imgWidth, imgHeight));
	ofRect(345, 50, imgWidth, imgHeight));
	ofRect(675, 50, imgWidth, imgHeight));
	ofRect(675, 320, imgWidth, imgHeight));

	
    ofFill();
    boxInputMatrix.draw(15, 50);
    boxOutput.draw(675, 50);

	
	
	//a arreglar 
	// finally, a report:
	char currentColor[1024];
	sprintf(currentColor, "current color: %d %d %d color detected %d", hue, sat, val, isTheColor);
	ofDrawBitmapString(currentColor, 20, 680);

	char colorMsg[1024];

	for (int i = 0; i < 5; i++) {
		ofFill();
		ofSetColor(colors[i][0], colors[i][1], colors[i][2]);
		ofRect(20, 700 - 10 + 15*i, 15, 15);
		sprintf(colorMsg, "color %d: %d %d %d", i, colors[i][0], colors[i][1], colors[i][2]);
		ofSetColor(0xffffff);
		ofDrawBitmapString(colorMsg, 50, 700 + 15*i);
	}

	ofSetColor(0x000000);

	



    string fpsStr = "frame rate: "+ofToString(ofGetFrameRate(), 2);
    ofDrawBitmapString(fpsStr, 15, 25);
}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){

	switch (key){
		case ' ': 
			
		#ifdef _USE_LIVE_VIDEO
			vidGrabber.videoSettings(); 

		#endif 
			
			break;

		case '0':
			colors[0][0] = hue;
			colors[0][1] = sat;
			colors[0][2] = val;

			break;

		case '1':
			colors[1][0] = hue;
			colors[1][1] = sat;
			colors[1][2] = val;

			break;

		case '2':
			colors[2][0] = hue;
			colors[2][1] = sat;
			colors[2][2] = val;

			break;

		case '3':
			colors[3][0] = hue;
			colors[3][1] = sat;
			colors[3][2] = val;

			break;

		case '4':
			colors[4][0] = hue;
			colors[4][1] = sat;
			colors[4][2] = val;

			break;


	}
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

    if(!boxOutput.adjustHandle(x, y))
        boxInputMatrix.adjustHandle(x, y);

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

