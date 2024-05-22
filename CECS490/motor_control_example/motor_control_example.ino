//Assign Names to Pins
const int Control_Pin = A0; //Control Pin

//Motor Driver Pins
const int IN1 = 13;
const int IN2 = 12;
const int ENA = 11;
 
void setup ()  
{
  // Motor
  pinMode(IN1, OUTPUT);  // Set the pin as OUTPUT 
  pinMode(IN2, OUTPUT);  // Set the pin as OUTPUT 
  pinMode(ENA, OUTPUT);   //PWM Pin
}  
void loop ()  
{
  int Control_Value = analogRead(Control_Pin);  // read the input on pin:
  int Motor_Speed = map(Control_Value, 0,1023, 0,255);
  analogWrite(ENA, Motor_Speed); //PWM Signal to control the speed of motor. (0 - 255)
  
  // Start Motor
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}