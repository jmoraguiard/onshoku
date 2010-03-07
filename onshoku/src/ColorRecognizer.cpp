/*
 *  ColorRecognizer.cpp
 *  openFrameworks
 *
 *  Created by biquillo on 07/02/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "ColorRecognizer.h"


ColorRecognizer::ColorRecognizer() {
	
} 

ColorRecognizer::ColorRecognizer(unsigned char *_pixels, int colors[5][3]) { 
	
	pixels = _pixels; 
	
	tileWidth = 320 / 8; 
	tileHeight = 240 / 8; 

	
	for (int j = 0; j < 4; j++) { 
		
		tileMatrix[j] = Tile(pixels, 0, j, tileWidth, tileHeight);
		
	} 
	
} 

void ColorRecognizer::update() { 
	
	//update tile 
	for (int j = 0; j < 4; j++) { 
		tileMatrix[j].detectColor(); 
		tileMatrix[j].update(); 
	} 
	
	printf("-----");
	
	
} 

void ColorRecognizer::draw() { 
	// load 
	ofPushMatrix(); 
	ofTranslate(20, 350); 

	//draw tiles 
	for (int j = 0; j < 4; j++) {
		tileMatrix[j].draw(); 
	} 
	
	ofPopMatrix(); 
} 




