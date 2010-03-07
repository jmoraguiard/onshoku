/*
 *  Matrix.h
 *  openFrameworks
 *
 *  Created by biquillo on 06/02/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef TILE_MATRIX_H 
#define TILE_MATRIX_H 


#include "Tile.h"

class TileMatrix {
public: 
	TileMatrix(); 
	TileMatrix(unsigned char *pixels, int colors[5][3]); 
	void draw(void); 
	void update(void); 
	
	
private: 
	
	unsigned char *pixels; 
	
	float tileWidth; 
	float tileHeight; 
	int tileColor; 
	int tileDrawColor; 
	
	void detectColor(); 
	void displayNoRecognized(); 
	void displayRecognized(); 
	void displaySound(); 
	
	
	Tile tileMatrix[8][8];  
	
	int colors[5][3]; 
	
	
	
	float time, beginning, change, duration; 
}; 


#endif 

