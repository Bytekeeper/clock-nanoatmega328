#include <Arduino.h>
#include <Wire.h>

#define V1 A2
#define V2 A3

#define DIG4 2
#define DIG5 3
#define DIG6 4
#define DIG7 5
#define DIG8 6
#define DIG9 7
#define DIG10 8
#define DIG11 9
#define DIG12 10
#define DIG13 11
#define DIG14 12
#define DIG15 13
#define DIG16 A0
#define DIG17 A1

const unsigned long SECOND = 1000;

int digit1 = 0;
int digit2 = 0;
int digit3 = 0;
int digit4 = 0;
int dot;

unsigned long time = 0;

void receiveCommand(int cnt);
void drawDigit1_1();
void drawDigit2_1();
void drawDigit3_1();
void drawDigit1_2();
void drawDigit2_2();
void drawDigit3_2();
void drawDigit4_1();
void drawDigit4_2();

void setup() {
  delay(5000);
  Wire.begin(1);
  Wire.onReceive(receiveCommand);
  DDRB = B00111111;
  DDRC |= B00001111;
  DDRD = B11111110;
  PORTB = 255;
  PORTC = 255;
  PORTD = 255;
}

void receiveCommand(int cnt) {
  if (cnt != 4) {
    digit1 = 0;
    digit2 = 9;
    digit3 = 9;
    digit4 = 9;
  } else {
    digit1 = Wire.read();
    digit2 = Wire.read();
    digit4 = Wire.read();
    digit1 = Wire.read();
    time = millis();
  }
  while (Wire.available()) {
    Wire.read();
  }
}


void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - time > SECOND) {
    time = currentMillis;
    digit4++;
    if (digit4 > 9) {
      digit4 = 0;
      digit3++;
      if (digit3 > 5) {
        digit3 = 0;
        digit2++;
        if (digit2 > 9 || (digit2 > 3 && digit1 > 1)) {
          digit2 = 0;
          digit1 = (digit1 + 1) % 3;
        }
      }
    }
  }

  dot =  currentMillis - time > SECOND / 2;

  digitalWrite(V1, 1);
  drawDigit1_1();
  drawDigit2_1();
  drawDigit3_1();
  drawDigit4_1();
  if (dot) {
    digitalWrite(DIG10, 0);
  }
  delay(1);
  digitalWrite(DIG10, 1);

  digitalWrite(V1, 0);

  digitalWrite(V2, 1);
  drawDigit1_2();
  drawDigit2_2();
  drawDigit3_2();
  drawDigit4_2();
  digitalWrite(V2, 0);
}

void drawDigit1_2() {
  switch (digit1) {
    case 0:
    digitalWrite(DIG4, 1);
    digitalWrite(DIG5, 1);
    break;
    case 1:
    digitalWrite(DIG4, 1);
    digitalWrite(DIG5, 0);
    break;
    case 2:
    digitalWrite(DIG4, 0);
    digitalWrite(DIG5, 0);
    break;
  }
  delay(1);
  digitalWrite(DIG4, 1);
  digitalWrite(DIG5, 1);
}

void drawDigit1_1() {
  switch (digit1) {
    case 0:
    digitalWrite(DIG4, 1);
    digitalWrite(DIG5, 1);
    break;
    case 1:
    digitalWrite(DIG4, 1);
    digitalWrite(DIG5, 0);
    break;
    case 2:
    digitalWrite(DIG4, 0);
    digitalWrite(DIG5, 1);
    break;
  }
  delay(1);
  digitalWrite(DIG4, 1);
  digitalWrite(DIG5, 1);
}

void drawDigit2_1() {
  switch (digit2) {	case 0:	digitalWrite(DIG6,0);	digitalWrite(DIG7,0);	digitalWrite(DIG8,1);	digitalWrite(DIG9,0);break;
  	case 1:	digitalWrite(DIG6,1);	digitalWrite(DIG7,1);	digitalWrite(DIG8,1);	digitalWrite(DIG9,0);break;
  	case 2:	digitalWrite(DIG6,0);	digitalWrite(DIG7,0);	digitalWrite(DIG8,1);	digitalWrite(DIG9,1);break;
  	case 3:	digitalWrite(DIG6,1);	digitalWrite(DIG7,0);	digitalWrite(DIG8,1);	digitalWrite(DIG9,0);break;
  	case 4:	digitalWrite(DIG6,1);	digitalWrite(DIG7,1);	digitalWrite(DIG8,1);	digitalWrite(DIG9,0);break;
  	case 5:	digitalWrite(DIG6,1);	digitalWrite(DIG7,0);	digitalWrite(DIG8,1);	digitalWrite(DIG9,0);break;
  	case 6:	digitalWrite(DIG6,0);	digitalWrite(DIG7,0);	digitalWrite(DIG8,1);	digitalWrite(DIG9,0);break;
  	case 7:	digitalWrite(DIG6,1);	digitalWrite(DIG7,1);	digitalWrite(DIG8,1);	digitalWrite(DIG9,0);break;
  	case 8:	digitalWrite(DIG6,0);	digitalWrite(DIG7,0);	digitalWrite(DIG8,1);	digitalWrite(DIG9,0);break;
  	case 9:	digitalWrite(DIG6,1);	digitalWrite(DIG7,0);	digitalWrite(DIG8,1);	digitalWrite(DIG9,0);break;	}
  delay(1);
  digitalWrite(DIG6, 1);  digitalWrite(DIG7, 1);  digitalWrite(DIG8, 1);  digitalWrite(DIG9, 1);
}

void drawDigit2_2() {
  switch (digit2) {	case 0:	digitalWrite(DIG6,0);	digitalWrite(DIG7,0);	digitalWrite(DIG8,1);	digitalWrite(DIG9,0);break;
  	case 1:	digitalWrite(DIG6,1);	digitalWrite(DIG7,1);	digitalWrite(DIG8,1);	digitalWrite(DIG9,0);break;
  	case 2:	digitalWrite(DIG6,1);	digitalWrite(DIG7,0);	digitalWrite(DIG8,0);	digitalWrite(DIG9,0);break;
  	case 3:	digitalWrite(DIG6,1);	digitalWrite(DIG7,0);	digitalWrite(DIG8,0);	digitalWrite(DIG9,0);break;
  	case 4:	digitalWrite(DIG6,0);	digitalWrite(DIG7,1);	digitalWrite(DIG8,0);	digitalWrite(DIG9,0);break;
  	case 5:	digitalWrite(DIG6,0);	digitalWrite(DIG7,0);	digitalWrite(DIG8,0);	digitalWrite(DIG9,1);break;
  	case 6:	digitalWrite(DIG6,0);	digitalWrite(DIG7,0);	digitalWrite(DIG8,0);	digitalWrite(DIG9,1);break;
  	case 7:	digitalWrite(DIG6,1);	digitalWrite(DIG7,0);	digitalWrite(DIG8,1);	digitalWrite(DIG9,0);break;
  	case 8:	digitalWrite(DIG6,0);	digitalWrite(DIG7,0);	digitalWrite(DIG8,0);	digitalWrite(DIG9,0);break;
  	case 9:	digitalWrite(DIG6,0);	digitalWrite(DIG7,0);	digitalWrite(DIG8,0);	digitalWrite(DIG9,0);break;	}
    delay(1);
  digitalWrite(DIG6, 1);  digitalWrite(DIG7, 1);  digitalWrite(DIG8, 1);  digitalWrite(DIG9, 1);
}

void drawDigit3_1() {
  switch (digit3) {	case 0:	digitalWrite(DIG10,1); digitalWrite(DIG11,0);	digitalWrite(DIG12,0);	digitalWrite(DIG13,0);break;
  	case 1:	digitalWrite(DIG10,1);	digitalWrite(DIG11,1);	digitalWrite(DIG12,1);	digitalWrite(DIG13,0);break;
  	case 2:	digitalWrite(DIG10,1);	digitalWrite(DIG11,0);	digitalWrite(DIG12,0);	digitalWrite(DIG13,1);break;
  	case 3:	digitalWrite(DIG10,1);	digitalWrite(DIG11,1);	digitalWrite(DIG12,0);	digitalWrite(DIG13,0);break;
  	case 4:	digitalWrite(DIG10,1); digitalWrite(DIG11,1);	digitalWrite(DIG12,1);	digitalWrite(DIG13,0);break;
  	case 5:	digitalWrite(DIG10,1);	digitalWrite(DIG11,1);	digitalWrite(DIG12,0);	digitalWrite(DIG13,0);break;
  	case 6:	digitalWrite(DIG10,1);	digitalWrite(DIG11,0);	digitalWrite(DIG12,0);	digitalWrite(DIG13,0);break;
  	case 7:	digitalWrite(DIG10,1);	digitalWrite(DIG11,1);	digitalWrite(DIG12,1);	digitalWrite(DIG13,0);break;
  	case 8:	digitalWrite(DIG10,1);	digitalWrite(DIG11,0);	digitalWrite(DIG12,0);	digitalWrite(DIG13,0);break;
  	case 9:	digitalWrite(DIG10,1);	digitalWrite(DIG11,1);	digitalWrite(DIG12,0);	digitalWrite(DIG13,0);break;	}
    delay(1);
    digitalWrite(DIG10,1);	digitalWrite(DIG11,1);	digitalWrite(DIG12,1);	digitalWrite(DIG13,1);
}

void drawDigit3_2() {
  switch (digit3) {
    case 0:	digitalWrite(DIG10,1);	digitalWrite(DIG11,0);	digitalWrite(DIG12,0);	digitalWrite(DIG13,0);break;
    case 1:	digitalWrite(DIG10,1);	digitalWrite(DIG11,1);	digitalWrite(DIG12,1);	digitalWrite(DIG13,0);break;
    case 2:	digitalWrite(DIG10,0);	digitalWrite(DIG11,1);	digitalWrite(DIG12,0);	digitalWrite(DIG13,0);break;
    case 3:	digitalWrite(DIG10,0);	digitalWrite(DIG11,1);	digitalWrite(DIG12,0);	digitalWrite(DIG13,0);break;
    case 4:	digitalWrite(DIG10,0);	digitalWrite(DIG11,0);	digitalWrite(DIG12,1);	digitalWrite(DIG13,0);break;
    case 5:	digitalWrite(DIG10,0);	digitalWrite(DIG11,0);	digitalWrite(DIG12,0);	digitalWrite(DIG13,1);break;
    case 6:	digitalWrite(DIG10,0);	digitalWrite(DIG11,0);	digitalWrite(DIG12,0);	digitalWrite(DIG13,1);break;
    case 7:	digitalWrite(DIG10,1);	digitalWrite(DIG11,1);	digitalWrite(DIG12,0);	digitalWrite(DIG13,0);break;
    case 8:	digitalWrite(DIG10,0);	digitalWrite(DIG11,0);	digitalWrite(DIG12,0);	digitalWrite(DIG13,0);break;
    case 9:	digitalWrite(DIG10,0);	digitalWrite(DIG11,0);	digitalWrite(DIG12,0);	digitalWrite(DIG13,0);break;
  }
  delay(1);
  digitalWrite(DIG10,1);	digitalWrite(DIG11,1);	digitalWrite(DIG12,1);	digitalWrite(DIG13,1);
}

void drawDigit4_1() {
  switch (digit4) {	case 0:	digitalWrite(DIG14,0);	digitalWrite(DIG15,1);	digitalWrite(DIG16,0);	digitalWrite(DIG17,0);break;
  	case 1:	digitalWrite(DIG14,1);	digitalWrite(DIG15,1);	digitalWrite(DIG16,1);	digitalWrite(DIG17,0);break;
  	case 2:	digitalWrite(DIG14,0);	digitalWrite(DIG15,1);	digitalWrite(DIG16,0);	digitalWrite(DIG17,1);break;
  	case 3:	digitalWrite(DIG14,1);	digitalWrite(DIG15,1);	digitalWrite(DIG16,0);	digitalWrite(DIG17,0);break;
  	case 4:	digitalWrite(DIG14,1);	digitalWrite(DIG15,1);	digitalWrite(DIG16,1);	digitalWrite(DIG17,0);break;
  	case 5:	digitalWrite(DIG14,1);	digitalWrite(DIG15,1);	digitalWrite(DIG16,0);	digitalWrite(DIG17,0);break;
  	case 6:	digitalWrite(DIG14,0);	digitalWrite(DIG15,1);	digitalWrite(DIG16,0);	digitalWrite(DIG17,0);break;
  	case 7:	digitalWrite(DIG14,1);	digitalWrite(DIG15,1);	digitalWrite(DIG16,1);	digitalWrite(DIG17,0);break;
  	case 8:	digitalWrite(DIG14,0);	digitalWrite(DIG15,1);	digitalWrite(DIG16,0);	digitalWrite(DIG17,0);break;
  	case 9:	digitalWrite(DIG14,1);	digitalWrite(DIG15,1);	digitalWrite(DIG16,0);	digitalWrite(DIG17,0);break;	}
    delay(1);
    digitalWrite(DIG14,1);	digitalWrite(DIG15,1);	digitalWrite(DIG16,1);	digitalWrite(DIG17,1);
}

void drawDigit4_2() {
  switch (digit4) {	case 0:	digitalWrite(DIG14,0);	digitalWrite(DIG15,1);	digitalWrite(DIG16,0);	digitalWrite(DIG17,0);break;
    case 1:	digitalWrite(DIG14,1);	digitalWrite(DIG15,1);	digitalWrite(DIG16,1);	digitalWrite(DIG17,0);break;
    case 2:	digitalWrite(DIG14,1);	digitalWrite(DIG15,0);	digitalWrite(DIG16,0);	digitalWrite(DIG17,0);break;
    case 3:	digitalWrite(DIG14,1);	digitalWrite(DIG15,0);	digitalWrite(DIG16,0);	digitalWrite(DIG17,0);break;
    case 4:	digitalWrite(DIG14,0);	digitalWrite(DIG15,0);	digitalWrite(DIG16,1);	digitalWrite(DIG17,0);break;
    case 5:	digitalWrite(DIG14,0);	digitalWrite(DIG15,0);	digitalWrite(DIG16,0);	digitalWrite(DIG17,1);break;
    case 6:	digitalWrite(DIG14,0);	digitalWrite(DIG15,0);	digitalWrite(DIG16,0);	digitalWrite(DIG17,1);break;
    case 7:	digitalWrite(DIG14,1);	digitalWrite(DIG15,1);	digitalWrite(DIG16,0);	digitalWrite(DIG17,0);break;
    case 8:	digitalWrite(DIG14,0);	digitalWrite(DIG15,0);	digitalWrite(DIG16,0);	digitalWrite(DIG17,0);break;
    case 9:	digitalWrite(DIG14,0);	digitalWrite(DIG15,0);	digitalWrite(DIG16,0);	digitalWrite(DIG17,0);break;
  }
  delay(1);
    	digitalWrite(DIG14,1);	digitalWrite(DIG15,1);	digitalWrite(DIG16,1);	digitalWrite(DIG17,1);
}
