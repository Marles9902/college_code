// constant variables
int E1 = 5;
int M1 = 4;
int E2 = 6;                    
int M2 = 2;                       

// setup baud + pins
void setup()
{
    Serial.begin (9600);
    pinMode(M1, OUTPUT);  
    pinMode(M2, OUTPUT);
}

// move motor
void loop()
{
  int potentiometerVal = analogRead(A0);
  Serial.println(potentiometerVal);
  move_motors(potentiometerVal);
}

// change speed of motor
void move_motors(int potValue)
{
    int mappedVal = map(potValue,0,1023,0,255);
    digitalWrite(M1,HIGH);  
    digitalWrite(M2, HIGH);      
    analogWrite(E1, mappedVal);   //PWM Speed Control
    analogWrite(E2, mappedVal);   //PWM Speed Control
    delay(30);  
}

