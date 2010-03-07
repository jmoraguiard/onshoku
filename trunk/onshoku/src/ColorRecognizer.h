/*
 *  ColorRecognizer.h
 *  openFrameworks
 *
 *  Created by biquillo on 07/02/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */



#ifndef COLOR_RECOGNIZER_H 
#define COLOR_RECOGNIZER_H 


#include "Tile.h"

class ColorRecognizer {
public: 
	ColorRecognizer(); 
	ColorRecognizer(unsigned char *pixels, int colors[5][3]); 
	void draw(void); 
	void update(void); 
	
	
private: 
	
	unsigned char *pixels; 
	
	float tileWidth; 
	float tileHeight; 

	
	void detectColor(); 
	void displayNoRecognized(); 
	void displayRecognized(); 
	void displaySound(); 
	
	
	Tile tileMatrix[4];  
	int colors[5][3]; 

	
	
	float time, beginning, change, duration; 
}; 


#endif 



