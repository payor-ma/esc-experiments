#include "esc-interface.h"

// Lookup table linking enable pins for H-bridges 1-3
// Modify depending on your pinout
// E.g. digitalWrite(en(1),LOW) turns off H-bridge 1
int en(int phase){
  switch (phase) {
    case 1:
      return 7;
      break;
    case 2:
      return 8;
      break;
    case 3:
      return 9;
      break;      
    default:
      error();
      break;
  }
}

// Lookup table linking High/Low switch pins for H-bridges 1-3
// Modify depending on your pinout
// E.g. digitalWrite(out(2),HIGH) switches H-bridge 2 to high side
int out(int phase){
  switch (phase) {
    case 1:
      return 15;
      break;
    case 2:
      return 14;
      break;
    case 3:
      return 16;
      break;      
    default:
      error();
      break;
  }
}

// Turns off all phases
void disable() {
  digitalWrite(en(1),LOW);
  digitalWrite(en(2),LOW);
  digitalWrite(en(3),LOW);
}

// For turning all phases off permanently in an invalid state
void error(){
  while (true) {
    disable();
  }
}

// Polling function for finding the state of a hall effect sensor
bool hall(int phase) {
    switch (phase) {
    case 1:
      if (digitalRead(2) == HIGH) {
        return true;
      } else { 
        return false;
      }
    case 2:
      if (digitalRead(3) == HIGH) {
        return true;
      } else { 
        return false;
      }
    case 3:
      if (digitalRead(4) == HIGH) {
        return true;
      } else { 
        return false;
      }    
    default:
      error();
      break;
  }
}
