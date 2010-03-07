/*
 *  Matrix.cpp
 *  openFrameworks
 *
 *  Created by biquillo on 06/02/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "TileMatrix.h"


TileMatrix::TileMatrix() {

}

TileMatrix::TileMatrix(unsigned char *_pixels, int colors[5][3] ) {

	pixels = _pixels;

	tileWidth = 640 / 8;
	tileHeight = 480 / 8;
	tileColor = 0x0000BB;
	tileDrawColor = 0x000000;

	time 		= 0;
	beginning	= 0;
	change 		= 500;
	duration 	= 1000;


	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tileMatrix[i][j] = Tile(pixels, i, j, tileWidth, tileHeight);
		}
	}

}

void TileMatrix::update() {

	if (time < duration) time++;

	//turnos deteccion

	//secuenciador
	for (int i = 0; i < 8; i++) {
		//tileMatrix[i][col].displaySound();
		//sonido
	}


	//update tile
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tileMatrix[i][j].detectColor();
			tileMatrix[i][j].update();
		}
	}

	printf("-----");


}

void TileMatrix::draw() {

	//draw tiles
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tileMatrix[i][j].draw();
		}
	}

}



