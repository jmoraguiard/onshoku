/*
 *  simpleOsc.cpp
 *  openFrameworks
 *
 *  Created by biquillo on 27/10/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "simpleOsc.h" 


//simpleOsc::simpleOsc() {
//	init();
	
	
//} 

void simpleOsc::init() {
	
	// listen on the given port
	cout << "listening for osc messages on port " << PORT << "\n";
	receiver.setup( PORT ); 
	
	current_msg_string = 0;
	mouseX = 0;
	mouseY = 0;
	mouseButtonState = "";
	
	
	//OSC
	// hide old messages
	for ( int i=0; i<NUM_MSG_STRINGS; i++ )
	{
		if ( timers[i] < ofGetElapsedTimef() )
			msg_strings[i] = "";
			}
	
	// check for waiting messages
	while( receiver.hasWaitingMessages() )
	{
		printf("qq");
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage( &m );
		
		// check for mouse moved message
		if ( m.getAddress() == "/test" ) {
			// both the arguments are int32's
			mouseX = m.getArgAsInt32( 0 );
			mouseY = m.getArgAsInt32( 1 );
			printf("Hola: %f", mouseX); 
			
		} else {
			// unrecognized message: display on the bottom of the screen
			string msg_string;
			msg_string = m.getAddress();
			msg_string += ": ";
			for ( int i=0; i<m.getNumArgs(); i++ )
			{
				// get the argument type
				msg_string += m.getArgTypeName( i );
				msg_string += ":";
				// display the argument - make sure we get the right type
				if( m.getArgType( i ) == OFXOSC_TYPE_INT32 )
					msg_string += ofToString( m.getArgAsInt32( i ) );
					else if( m.getArgType( i ) == OFXOSC_TYPE_FLOAT )
						msg_string += ofToString( m.getArgAsFloat( i ) );
						else if( m.getArgType( i ) == OFXOSC_TYPE_STRING )
							msg_string += m.getArgAsString( i );
							else
								msg_string += "unknown";
								}
			// add to the list of strings to display
			msg_strings[current_msg_string] = msg_string;
			timers[current_msg_string] = ofGetElapsedTimef() + 5.0f;
			current_msg_string = ( current_msg_string + 1 ) % NUM_MSG_STRINGS;
			// clear the next line
			msg_strings[current_msg_string] = "";
		}
		
	}
	
	
	printf("hola %i: ", receiver.hasWaitingMessages()); 

	
}

bool simpleOsc::sendMsg(string msg) {
	
}

string simpleOsc::receiveMsg() { 
	
}



