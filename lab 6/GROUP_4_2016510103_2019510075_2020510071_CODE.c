int led = 3;
int LED_ACTIVATION_VALUE = 500;
int SERIAL_OUTPUT_FREQUENCY = 500; 
void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
  int ldr_sensor = analogRead(A0);
  Serial.print("LIGHT SENSOR : ");
  Serial.println(String(ldr_sensor));
  if(ldr_sensor<=LED_ACTIVATION_VALUE){
    digitalWrite(led,HIGH);
    Serial.println("LIGHT SENSOR : OFF");
  }
  else{
    digitalWrite(led,LOW);
    Serial.println("LIGHT SENSOR : ON");
  }
  delay(SERIAL_OUTPUT_FREQUENCY);
}
