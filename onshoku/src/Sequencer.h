#ifndef SEQUENCER_H
#define SEQUENCER_H

#include "ofMain.h"

class Sequencer {

public:
	Sequencer();
	void draw(void);
	void update(void);

private:

    float ellapsedTime;
    float oldEllapsedTime;
    float tempoDuration;

    int tempoCounter;

};


#endif


