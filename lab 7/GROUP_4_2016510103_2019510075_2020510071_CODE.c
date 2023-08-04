#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 9;
const int echoPin = 10;
const int level4 = 8;
const int level3 = 11;
int BUZZER_LED_FREQ_MAX = 1000;
int BUZZER_LED_FREQ_MIN = 10;
int DIST_MAX = 100;
int DIST_MIN = 10;
int CURRENT_DIST = 0;
int CURRENT_FREQ = 0;
int UPDATE_FREQ_BUZZER = 200;
int UPDATE_FREQ_LCD = 200;

// defines variables
long duration;
int safetyDistance;
int freqFunc(int currentDist){
  if (currentDist > DIST_MAX) {
    currentDist = DIST_MAX;
  } else if (currentDist < DIST_MIN) {
    currentDist = DIST_MIN;
  }
  CURRENT_FREQ = ((currentDist - DIST_MIN) / (float)(DIST_MAX - DIST_MIN)) * (BUZZER_LED_FREQ_MAX - BUZZER_LED_FREQ_MIN) + BUZZER_LED_FREQ_MIN;
  if (CURRENT_FREQ > BUZZER_LED_FREQ_MAX) {
    CURRENT_FREQ = BUZZER_LED_FREQ_MAX;
  } else if (CURRENT_FREQ < BUZZER_LED_FREQ_MIN) {
    CURRENT_FREQ = BUZZER_LED_FREQ_MIN;
  }
  if (currentDist >= DIST_MAX) {
    CURRENT_FREQ = BUZZER_LED_FREQ_MIN;
  }
  return CURRENT_FREQ;
}




void setup() {
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(level4, OUTPUT);
  pinMode(level3, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  lcd.clear();
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  CURRENT_DIST = duration * 0.034 / 2;
  safetyDistance = CURRENT_DIST;

  if (CURRENT_DIST <= DIST_MAX) {
    CURRENT_FREQ = freqFunc(CURRENT_DIST);
    tone(level4, CURRENT_FREQ);
    digitalWrite(level3, HIGH);

    lcd.setCursor(0, 0);
    lcd.print("DISTANCE: ");
    lcd.print(CURRENT_DIST);
    lcd.print(" cm");

    lcd.setCursor(0, 1);
    lcd.print("FREQUENCY: ");
    lcd.print(CURRENT_FREQ);
    lcd.print(" ms");
  } 
  else if(CURRENT_DIST >= DIST_MIN) {
    noTone(level4);
    digitalWrite(level3, LOW);
  }

  // Prints the distance and frequency on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(CURRENT_DIST);
  Serial.print(" cm");

  Serial.print(" Frequency: ");
  Serial.print(CURRENT_FREQ);
  Serial.println(" ms");

  delay(UPDATE_FREQ_BUZZER);
}

