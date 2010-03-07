/*
 *  simpleOsc.h
 *  openFrameworks
 *
 *  Created by biquillo on 27/10/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef SIMPLE_OSC_H 
#define SIMPLE_OSC_H 

#include "ofxOsc.h"

// listen on port 12345
#define PORT 12000
#define NUM_MSG_STRINGS 20


class simpleOsc {
public:
	//simpleOsc();
	bool sendMsg(string msg);
	string receiveMsg(void);
	
private: 
	
	void init();
	ofxOscReceiver	receiver;
	
	int				current_msg_string;
	string			msg_strings[NUM_MSG_STRINGS];
	float			timers[NUM_MSG_STRINGS]; 
	
	int				mouseX, mouseY;
	string			mouseButtonState;
	
	
}; 


#endif 


