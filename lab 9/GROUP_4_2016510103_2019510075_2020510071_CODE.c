#define led 2
#define enA 3
#define in1 4
#define in2 5

int LED_WAIT_DURATION_MIN = 2000;
int LED_WAIT_DURATION_MAX = 6000;

int LIGHT_SENSOR_OUTPUT_INTERVAL = 1000;

int rand_wait = 0;
int led_status = 0;
int sensor_counter = 1;
int motor_status = 0;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  
  rand_wait = random(LED_WAIT_DURATION_MIN, LED_WAIT_DURATION_MAX);
  Serial.begin(9600);
  Serial.print("LED is turned OFF for ");
  Serial.print(rand_wait);
  Serial.print(" milliseconds.");
  Serial.println();
}

void loop()
{
  long start_time = micros();
  
  if (led_status == 0) {
    if (millis() >= rand_wait) {
      digitalWrite(led, HIGH);
      led_status = 1;
      rand_wait = millis() + random(LED_WAIT_DURATION_MIN, LED_WAIT_DURATION_MAX);
      motor_status = 1;
      Serial.println();
      Serial.print("LED is turned ON for ");
      Serial.print(rand_wait);
      Serial.print(" milliseconds.");
      Serial.println();
      Serial.println();
    }
  }
  else if (led_status == 1) {
    if (millis() >= rand_wait) {
      digitalWrite(led, LOW);
      led_status = 0;
      rand_wait = millis() + random(LED_WAIT_DURATION_MIN, LED_WAIT_DURATION_MAX);
      motor_status = 0;
      Serial.println();
      Serial.print("LED is turned OFF for ");
      Serial.print(rand_wait);
      Serial.print(" milliseconds.");
      Serial.println();
      Serial.println();
    }
  }
  
  sensor();
  motor();
  
  long end_time = micros();
  if ((1000 - (end_time - start_time)) > 0)
    delayMicroseconds(1000 - (end_time - start_time));
}

void sensor() {
  if (sensor_counter >= LIGHT_SENSOR_OUTPUT_INTERVAL) {
    int sensor_value = analogRead(A0);
    Serial.print("Light sensor output is ");
    Serial.print(sensor_value);
    Serial.print(".");
    Serial.println();
    sensor_counter = 0;
  }
  sensor_counter++;
}

void motor() {
  if (motor_status == 0) {
    digitalWrite(enA, HIGH);
  }
  else {
    digitalWrite(enA, LOW);
  }
}
