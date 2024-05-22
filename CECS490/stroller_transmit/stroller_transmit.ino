#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

struct sensorData{
  int fsrValue;
  int potValue;
};

void setup() {
  Serial.begin(9600);  // For debugging purposes
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  // Read the analog value from the FSR
  int fsrValue = analogRead(A0);

  // Read the analog value from the potentiometer
  int potValue = analogRead(A1);

  // struct instances to assign values
  sensorData data;
  data.fsrValue = fsrValue;
  data.potValue = potValue;
  // Send the FSR value
  radio.write(&data, sizeof(data));

  // For debugging purposes, print the FSR and potentiometer values to Serial
  Serial.print("FSR Value: ");
  Serial.println(fsrValue);
  
  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);

  delay(1000);
}