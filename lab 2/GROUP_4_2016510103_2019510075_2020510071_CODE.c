int pin2 = 2;
int pin3 = 3;
int pin4 = 4;
int pin5 = 5;
int pin6 = 6;
int INCREMENT_VALUE = 15;
int WAIT_TIME = 500;
int i=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(true){
    if ( i % 2 )
    { digitalWrite(pin2,HIGH); }
    else 
    { digitalWrite(pin2,LOW);   }
    if ( (i / 2 )  % 2 ) 
    { digitalWrite(pin3,HIGH); } 
    else 
    { digitalWrite(pin3,LOW);}
    if ( ( i / 4 ) % 2 ) 
    { digitalWrite(pin4,HIGH); } 
    else 
    { digitalWrite(pin4,LOW); }
    if ( (i / 8 ) % 2 ) 
    { digitalWrite(pin5,HIGH); } 
    else { digitalWrite(pin5,LOW); }
    if ( (i / 16 ) % 2 ) 
    { digitalWrite(pin6,HIGH);  } 
    else 
    { digitalWrite(pin6,LOW);}
    i=i+INCREMENT_VALUE;
    delay(WAIT_TIME);
  }
  
  



}