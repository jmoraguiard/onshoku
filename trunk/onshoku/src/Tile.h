/*
 *  Tile.h
 *  openFrameworks
 *
 *  Created by biquillo on 06/02/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef TILE_H
#define TILE_H

#include "ofMain.h"

//
//#include "Quad.h"
//#include "Quart.h"
//#include "Quint.h"
//#include "Sine.h"
//#include "Linear.h"
//#include "Expo.h"
//#include "Elastic.h"
//#include "Cubic.h"
//#include "Circ.h"
//#include "Bounce.h"
//#include "Back.h"



class Tile {
public:
	Tile();
	Tile(unsigned char *pixels, int i, int j, float _tileWidth, float _tileHeight);
	void draw(void);
	void update(void);

	void detectColor();
	void displayNotRecognized();
	void displayRecognized();
	void displaySound();

	bool isEnabled;


private:

	unsigned char *pixels;

	int posX;
	int posY;

	int tileX;
	int tileY;
	float tileWidth;
	float tileHeight;
	int tileColor;
	int tileDrawColor;


	int hue;
	int sat;
	int val;

	int colors[5][3];
	int isTheColor;


	int ellipseSize;


	float time, beginning, change, duration;


	int tempX;
	int tempY;


};


#endif


