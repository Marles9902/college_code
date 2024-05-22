// libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

// declarations
Servo brakeServos;    // initialize servos
byte character = 0;   // initialize communication with Pi

// pins for DC motors
int E1 = 5; // enable pin for motor 1
int E2 = 6; // enable pin for motor 2
int M1 = 4; // motor 1 pin
int M2 = 2; // motor 2 pin

// globals
const int pressureThreshold = 100;  // threshold for human touch, air can make FSR finicky 
const int servoSpeed = 2;           // smaller = slower speed for increment
bool brakesEngaged = false;         // check if brakes engaged
bool fsrActive = false;             // flag for if someone touching

// radio receive setup
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001"; // radio channel

// structure for multiple sensor data
struct sensorData{
  int fsrValue;
  int potValue;
};

// attribute sensor datas to received values
sensorData receivedValue;

// setup
void setup() {
  Serial.begin(9600);     // serial communication for Pi, currently set for serial monitor
  brakeServos.attach(10); // Attach servo to pin 10
  
  // radio setup
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  
  // configure motor pins as outputs
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
}

void loop() {
 motors();  // call motors
}

// place DC motor code as function
void DC_motor() {
      // Read the potentiometer value
    int potValue = receivedValue.potValue;

    // Map the potentiometer value to the range of motor speeds (0-255)
    int motorSpeed = map(potValue, 0, 1023, 0, 255);

    // Set the motor speed
    delay(500);                  // delay of 0.5s from when DCs activate
    digitalWrite(M1, HIGH);      // activate motor 1
    digitalWrite(M2, HIGH);      // activate motor 2
    analogWrite(E1, motorSpeed); // potentiometer read
    analogWrite(E2, motorSpeed); // Assuming the DC motor is connected to pin 4
    delay(30);                   // stop DCs fast
} 

void DC_motor_off(){
    // turn motor off
    int motorSpeed = 255;

    // Set the motor speed
    delay(30);                  // delay of 0.5s from when DCs activate
    digitalWrite(M1, HIGH);      // activate motor 1
    digitalWrite(M2, HIGH);      // activate motor 2
    analogWrite(E1, motorSpeed); // potentiometer read
    analogWrite(E2, motorSpeed); // Assuming the DC motor is connected to pin 4
    delay(30);                   // stop DCs fast
}

// set servos/DC into one function
void motors(){

  if (radio.available()) {

    radio.read(&receivedValue, sizeof(receivedValue));

    // threshold checks
    if (receivedValue.fsrValue >= pressureThreshold){
      fsrActive = true;         // NEW -- if person touching, let system know
      if (brakesEngaged){       // if braking
        brakeServos.write(90);  // remove brakes
        brakesEngaged = false;  // let system know brakes are off
      }
      else{                     // otherwise if not in braking (use case for if accidentally let go and touch again)
        brakeServos.write(90);  // still release brakes
      }
      DC_motor();               // if FSR is being touched, allow for DC motor usage
    }
    
    else{   // NEW 
      DC_motor_off();
      
      // if not in braking (brakes released) and fsr not touched
      if (!brakesEngaged){
        brakesEngaged = true;  // let system know to go back to braking
        // for loop for putting servos slowly back into place
        for (int pos = brakeServos.read(); pos >= 0; pos -= servoSpeed){
          brakeServos.write(pos); 
          delay(15);

          // if person touches fsr again while brakes are being applied again
          radio.read(&receivedValue.fsrValue, sizeof(receivedValue.fsrValue));
          if (receivedValue.fsrValue >= pressureThreshold){
            fsrActive = true;      // NEW
            brakeServos.write(90); // release brakes again
            //DC_motor();            // let DCs go again if toggled
            brakesEngaged = false; // let system know brakes off
            //break;                 // break out loop
          }
        }
      }
    }
  }
}