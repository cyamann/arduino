#define P1A 2 // define pin 2 as for P1A
#define P2A 7 // define pin 7 as for P2A
#define EN12 8 // define pin 8 as for 1,2EN enable

// DC motor 2 control 
#define P3A 10 // define pin 10 as for P3A
#define P4A 13 // define pin 13 as for P4A
#define EN34 9 // define pin 9 as for EN3 and EN4 enable
int button_right = A1;
int button_left = A0;
int MOTOR_STEPS = 10;
int currentStep = 0;
const int G = 12;
const int F = 11;
const int A = 10;
const int B = 9;
const int E = 3;
const int D = 4;
const int C = 5;
bool left = false;
bool right = false;
const int driverPin1 = 2;
const int driverPin2 = 4;
const int enablePin = 3;
void setup() {
  
  Serial.begin(9600);
    
  pinMode(P1A, OUTPUT);// define pin as OUTPUT for P1A
  pinMode(P2A, OUTPUT);// define pin as OUTPUT for P2A
  pinMode(EN12, OUTPUT);// define pin as OUTPUT for 1,2EN
   
  pinMode(P3A, OUTPUT);// define pin as OUTPUT for P3A
  pinMode(P4A, OUTPUT);// define pin as OUTPUT for P4A
  pinMode(EN34, OUTPUT);// define pin as OUTPUT for 3,4EN   

  pinMode(button_right,INPUT); 
  pinMode(button_left,INPUT); 
  pinMode(G, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(C, OUTPUT);
  zero();
  if (MOTOR_STEPS > 10 || MOTOR_STEPS < 0)
  {
    Serial.println("MOTOR_STEPS value should be between 0 and 10 (both included).");
    Serial.flush();
    Serial.println("Assigned default value 5 to MOTOR_STEPS.");
    Serial.flush();
    MOTOR_STEPS = 5;
  }
}


void loop() {
  // L293 Motor Control Code by Robojax.com 2018025

	int Button_r =  digitalRead(button_right);
    int Button_l =  digitalRead(button_left);

  if(Button_r == 1 && currentStep < MOTOR_STEPS && !right){//cw
    currentStep++;
    updateDisplay();
    updateMotor();
	  right = true;
  }
   else if (Button_r == 0)
  {
    right = false;
  }
  if(Button_l == 1 && currentStep > -MOTOR_STEPS && !left){//ccw
    currentStep--;
    updateDisplay();
    updateMotor();
    left = true;
  }
   else if (Button_l==0)
  {
    left = false;
  }
}

void updateMotor()
{
   // Calculating the duty cycle percentage.
  int analogInput = 255.0 * ((float)abs(currentStep) / MOTOR_STEPS);
    
  if (currentStep == 0)  // Stop motor.
  {
    digitalWrite(EN12, 0);
  }
  else if (currentStep < 0) // Spin counter-clockwise.
  {
    digitalWrite(EN12 ,HIGH);// Enable 1A and 2A     
    digitalWrite(P1A,LOW);// send + or HIGH singal to P1A
    digitalWrite(P2A,HIGH);// send - or LOW singal to P2A  
    delay(3000);// motor runs for 3 seconds
    digitalWrite(EN12 ,LOW);// Disable 1A and 2A   
  }
  else if (currentStep > 0) // Spin clockwise.
  {
   digitalWrite(EN12 ,HIGH);// Enable 1A and 2A 
    digitalWrite(P1A,HIGH);// send + or HIGH singal to P1A
    digitalWrite(P2A,LOW);// send - or LOW singal to P2A       
    delay(3000);// motor runs for 3 seconds
    digitalWrite(EN12 ,LOW);// Disable 1A and 2A
  }
}

// This method displays the number on the seven segment display.
void updateDisplay()
{
  if (abs(currentStep) == 0) zero();
  else if (abs(currentStep) == 1) one();
  else if (abs(currentStep) == 2) two();
  else if (abs(currentStep) == 3) three();
  else if (abs(currentStep) == 4) four();
  else if (abs(currentStep) == 5) five();
  else if (abs(currentStep) == 6) six();
  else if (abs(currentStep) == 7) seven();
  else if (abs(currentStep) == 8) eight();
  else if (abs(currentStep) == 9) nine();
}



void zero()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}

void one()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void two()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
}

void three()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
}

void four()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void five()
{
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void six()
{
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void seven()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void eight()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void nine()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}
