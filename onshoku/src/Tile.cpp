/*
 *  Tile.cpp
 *  openFrameworks
 *
 *  Created by biquillo on 06/02/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Tile.h"


Tile::Tile() {
	int tileWidth = 20;
	int tileHeight = 20;
}


Tile::Tile(unsigned char *_pixels, int _posX, int _posY, float _tileWidth, float _tileHeight ) {
	pixels = _pixels;
	posX = _posX;
	posY = _posY;

	isEnabled = false;

	tileWidth = _tileWidth;
	tileHeight = _tileHeight;

	tileX = posX * tileWidth;
	tileY = posY * tileHeight;

	//printf("hola %d %d ", i, j);


	tileColor = 0x0000BB;
	tileDrawColor = 0x000000;

	ellipseSize = 0;

	time 		= 0;
	beginning	= 0;
	change 		= 500;
	duration 	= 1000;

	hue = 0;
	sat = 0;
	val = 0;

}

void Tile::update() {
	if (time < duration) time++;

	//ellipseSize = Quad::easeOut(time, beginning, change, duration);

}

void Tile::draw() {

	// load
	ofPushMatrix();
	ofTranslate(tileX, tileY);

	ofFill();
	ofSetColor(hue, sat, val);
	ofRect(0, 0, tileWidth, tileHeight);

	//ofNoFill();
	//ofSetColor(0x000000);
	//ofRect(0, 0, tileWidth, tileHeight);


	ofPopMatrix();



	//ofPushMatrix();
	//ofTranslate(20, 20);
	//ofSetColor(0xFFFFFF);
	//ofRect(tempX, tempY, tileWidth, tileHeight);
	//ofPopMatrix();


}


void Tile::detectColor() {
	//meter codigo aqui
	//unsigned char * pixels = colorImg.getPixels();


	//printf("p3: %p\r\n", pixels);

	hue = 0;
	sat = 0;
	val = 0;


	int imageStartX = tileWidth * posX;
	int imageStartY = tileHeight * posY;
	int imageEndX = tileWidth * posX + tileWidth;
	int imageEndY = tileHeight * posY + tileHeight;
	int imageSize = (imageEndX - imageStartX) * (imageEndY - imageStartY);

	int count = 0;

	for (int y = imageStartY; y < imageEndY; y++) { //30 ..... 40
		for (int x = imageStartX; x < imageEndX; x++) { //0 ..... 40
			//printf("x: %d y: %d\r\n", y, x);

			int index = y * 640 * 3 + x * 3;
			hue += pixels[index];
			sat += pixels[index + 1];
			val += pixels[index + 2];

			count++;

			//printf("%d ", index);

		}
	}

	//printf("\r\n");
	//printf("%d \r\n", count);



	//printf("hola %d %d %d %d %d\r\n", imageStartX, imageStartY, imageEndX, imageEndY, imageSize );

	hue = hue / (imageSize);
	sat = sat / (imageSize);
	val = val / (imageSize);


	tempX = imageStartX;
	tempY = imageStartY;


	float possibleColor = 1000;

	for (int i = 0; i < 5; i++) {

		float c = sqrt(pow((colors[i][0] - hue), 2) +
					   pow((colors[i][1] - sat), 2) +
					   pow((colors[i][2] - val), 2));

		if (c < possibleColor) {
			possibleColor = c;
			isTheColor = i;
		}


	}



	//if color recognized
	displayRecognized();
	//if not
	displayNotRecognized();
}


void Tile::displayNotRecognized() {



}

void Tile::displayRecognized() {

	ofFill();
	ofEllipse(0, 0, 20, 20);
	ofSetColor(tileDrawColor);



	ofSetColor(0xa0f0a0);
	//ofRect(	Quad::easeIn    (time, beginning, change, duration),0 ,10,10);
	//ofRect(	Quad::easeOut   (time, beginning, change, duration),10,10,10);

	//ofEllipse(0, 0, ellipseSize, ellipseSize);
	//ofRect(	Quad::easeInOut (time, beginning, change, duration),20,10,10);



}

void Tile::displaySound() {
	if (isEnabled) {

	}


}







