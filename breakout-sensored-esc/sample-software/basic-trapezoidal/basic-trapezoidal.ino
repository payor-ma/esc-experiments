#include "esc-interface.h"

void setup() {
  // phase outputs
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  // enable outputs
  pinMode(15, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(16, OUTPUT);

  // hall inputs
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);

}

// Calls the trapezoidal function and sets RPM by a delay
// Delay defines the RPM as a function of the motor poles
void loop() {
 
  trap();
  delayMicroseconds(150);

}

// Sets a trapezoidal state, explained inline:
void set(int off, int low, int high){
  digitalWrite(en(off),LOW);    // One output is off
  digitalWrite(en(low),HIGH);   // The other 2 outputs are on
  digitalWrite(en(high),HIGH);  // ^
  digitalWrite(out(low),LOW);   // One of the two outputs is low side
  digitalWrite(out(high),HIGH); // The other is high side
}

// Trapezoidal lookup table linking phase outputs to sensor inputs
// See the table in this directory
void trap() {
  if (hall(1)) {
    if (hall(2)) {
      if (hall(3)) {
        disable();
      } else {
        set(2,1,3);    
      }
    } else {
       if (hall(3)) {
        set(1,3,2);
      } else {
        set(3,1,2);    
      }     
    }
  } else {
    if (hall(2)) {
      if (hall(3)) {
        set(3,2,1);
      } else {
        set(1,2,3);    
      }
    } else {
       if (hall(3)) {
        set(2,3,1);
      } else {
        disable();    
      }     
    }
  }  

}



  
