int TIMER_START = 30;
int TIMER_SPEED = 500;
int ANIMATION_SPEED = 200;

byte pin[] = {2, 3, 4, 5, 6, 7, 8, 9}; // arduino pin array
int number[16][8] = {
 //a b c d e f g h
  {0,0,0,0,0,0,0,1}, // 0
  {1,1,0,1,0,1,1,1}, // 1
  {0,0,1,1,0,0,1,0}, // 2
  {1,0,0,1,0,0,1,0}, // 3
  {1,1,0,1,1,1,0,0}, // 4
  {1,0,0,1,1,0,0,0}, // 5
  {0,0,0,1,1,0,0,0}, // 6
  {1,1,0,1,0,0,1,1}, // 7
  {0,0,0,1,0,0,0,0}, // 8
  {1,0,0,1,0,0,0,0}, // 9
  {0,1,0,0,0,0,0,0}, // A
  {0,0,0,0,1,1,0,0}, // B
  {0,0,1,1,1,0,0,1}, // C
  {0,0,0,1,0,1,1,0}, // D
  {0,0,1,0,1,0,0,0}, // E
  {0,1,1,0,1,0,0,0}  // F
};
int animation[6][8]={
  {1,1,1,1,1,0,1,1},
  {1,1,1,1,0,1,1,1},
  {1,1,0,1,1,1,1,1},
  {1,0,1,1,1,1,1,1},
  {0,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,0,1}
};

void anim() {
  unsigned long startTime = millis();
  while (millis() - startTime < (TIMER_START - 15) * 1000) { // run for TIMER_START - 15 seconds
    digitalWrite(13,HIGH);
    for (int a = 0; a < 6; a++) {
      for (int b = 0; b < 8; b++) {
        digitalWrite(pin[b], animation[a][b]);
      }
      delay(ANIMATION_SPEED);
    }
  }
}


void setup() {
  Serial.begin(9600);// setup Serial Monitor to display information
  pinMode(12, INPUT);// Input from sensor
  pinMode(13, OUTPUT);// OUTPUT to alarm or LED
  for (byte a = 0; a < 8; a++) {
    pinMode(pin[a], OUTPUT); // define output pins
  }
}

void loop() {
  int motion = digitalRead(12);
  if(motion){
    anim();
    for (int a = 15; a >= 0; a--) {
      for (int b = 0; b < 8; b++) {
        digitalWrite(13,HIGH);
       digitalWrite(pin[b], number[a][b]);//display numbers
      }
      delay(TIMER_SPEED);//delay
    }
    digitalWrite(13,LOW);
  delay(15000);
  }
}
