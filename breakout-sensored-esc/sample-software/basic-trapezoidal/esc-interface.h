#ifndef escInterface_h
#define escInterface_h

#include "Arduino.h"


// Lookup table linking enable pins for H-bridges 1-3
// Modify depending on your pinout
// E.g. digitalWrite(en(1),LOW) turns off H-bridge 1
int en(int phase);

// Lookup table linking High/Low switch pins for H-bridges 1-3
// Modify depending on your pinout
// E.g. digitalWrite(out(2),HIGH) switches H-bridge 2 to high side
int out(int phase);

// Turns off all phases
void disable();

// For turning all phases off permanently in an invalid state
void error();

// Polling function for finding the state of a hall effect sensor
bool hall(int phase);

#endif
