int ledPin1 = 10;
int ledPin2 = 11;
int ledBright;

int pot1 = A0;

int potRead = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(ledPin1, HIGH); // Sets the signal in 3 to HIGH (turn on the LED) and 4 and 5 to LOW (turn off the LEDs connected to 4 and 5)
  //digitalWrite(ledPin2, HIGH); // Sets the signal in 3 to HIGH (turn on the LED) and 4 and 5 to LOW (turn off the LEDs connected to 4 and 5)
  //analogWrite(ledPin1, 10);


  potRead = analogRead(pot1);
  
  int mapped = map(potRead, 0, 700, 0, 255);
  
  Serial.println(potRead);

  ledBright = mapped;

  analogWrite(ledPin1, ledBright);

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
