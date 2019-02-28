int tonePin = 8;
int photoPin = A0;
int photoRead = 0;

int lowLimit = 0;
int highLimit = 600;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(ledPin1, HIGH); // Sets the signal in 3 to HIGH (turn on the LED) and 4 and 5 to LOW (turn off the LEDs connected to 4 and 5)
  //digitalWrite(ledPin2, HIGH); // Sets the signal in 3 to HIGH (turn on the LED) and 4 and 5 to LOW (turn off the LEDs connected to 4 and 5)
  //analogWrite(ledPin1, 10);

  if(photoRead < lowLimit){
    photoRead = lowLimit;
  }
  if(photoRead > highLimit){
    photoRead = highLimit;
  }

  photoRead = analogRead(photoPin);
  
  int mapped = map(photoRead, 60, 1020, 31, 4978);
  
  Serial.println(photoRead);
  Serial.println(mapped);
  

 //tone(tonePin,mapped,100);


  /*if (potRead < 512) {
    analogWrite(ledPin2, ledBright);
    analogWrite(ledPin1, 0);
  }
  if (potRead > 512) {
    analogWrite(ledPin2, 0);
    analogWrite(ledPin1, ledBright);
  }
  */

  /*for (int i=0; i<255; i++)
    {
    analogWrite(ledPin1,i);
    delay(50);

    if(i==255){
    i=0;
    delay(1000);
    }
    }
  */



}
