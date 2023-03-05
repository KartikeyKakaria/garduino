#include <Servo.h>
Servo myservo;

void setup() {
  myservo.attach(2); //attaching servo to pin D2
  pinMode(A0, INPUT_PULLUP); // attaching soil moisture sensor to A0 pin
  pinMode(A1, OUTPUT); // attaching relay to pin D1
  digitalWrite(1,HIGH); // giving the relay a state of high to keep it off
  Serial.println('Hello world from GARDUINO');
}

//function to start the watering system
void startSystem(){
  myservo.write(180);
  delay(1000);
  myservo.write(0);
  delay(300);
  digitalWrite(A1,LOW);
}

void loop() {
  int soilMoisture = analogRead(A0);
  bool needsToWater = soilMoisture <= 850; // if soil moisture is less
  if(needsToWater){
    startSystem(); //yeah thats what it does
  }else{
    myservo.write(0); // or bring the servo to 0;
    digitalWrite(A1, HIGH); // off the relay
  }
}
