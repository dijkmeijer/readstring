/*
  Reading a serial ASCII-encoded string.

  This sketch demonstrates the Serial parseInt() function.
  It looks for an ASCII string of comma-separated values.
  It parses them into ints, and uses those to fade an RGB LED.

  Circuit: Common-Cathode RGB LED wired like so:
   Red anode: digital pin 3
   Green anode: digital pin 5
   Blue anode: digital pin 6
   Cathode : GND

  created 13 Apr 2012
  by Tom Igoe

  modified 14 Mar 2016
  by Arturo Guadalupi

  This example code is in the public domain.
*/

// pins for the LEDs:
byte b, c, d;
boolean list[] = {HIGH, HIGH, HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW, LOW};
int i;
int input[3];


void setup() {
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  i = 0;


}

void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {
    b = Serial.read();
    input[i % 3] = b - '0';
    if (b == '\n') {
      digitalWrite(8, list[input[(i + 2) % 3]]);
      digitalWrite(7, list[input[(i + 1) % 3]]);
      i = 0;
    }
    else i++;
  }
}








