#include <Servo.h>

int ledPin1 = 3;
int counter = 0;

long prevMillis = 0;
int interval = 10;

boolean flipFlop = false;

Servo myservo;

void setup() {
  // put your setup code here, to run once:
//pinMode(ledPin1, OUTPUT);
myservo.attach(3);
}


void loop() {
  // put your main code here, to run repeatedly:
  
  //counter = counter + 1;

  myservo.write(counter);
  
  if (millis() - prevMillis >= interval){
    prevMillis = millis();
    
    if (flipFlop == false){
      counter = counter+1;
    }
    else if (flipFlop == true){
      counter = counter-1;
    }
  }

    if (counter >= 180){
        flipFlop = true;
      }
    if (counter <= 0){
       flipFlop = false;
    }
    
  }

  
//  if(counter>= 255){
//  counter = counter-1;
//  }
//  delay(100);
//  Serial.println(counter);
  
