int buttonLight = 9;

int led1 = 3;
int led2 = 4;
int led3 = 5;
int led4 = 6;
int led5 = 7;
int led6 = 8;

void setup() {
    
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
    pinMode(led3,OUTPUT);
    pinMode(led4,OUTPUT);
    pinMode(led5,OUTPUT);
    pinMode(led6,OUTPUT);
    pinMode(buttonLight, INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
    int lightButton = digitalRead(buttonLight);

     if(lightButton == LOW){
         analogWrite(led1, 0);
         analogWrite(led2, 0);
         analogWrite(led3, 0);
         analogWrite(led4, 0);
         analogWrite(led5, 0);
         analogWrite(led6, 0);
    }
   else if(lightButton == HIGH){
         analogWrite(led1, 255);
         analogWrite(led2, 255);
         analogWrite(led3, 255);
         analogWrite(led4, 255);
         analogWrite(led5, 255);
         analogWrite(led6, 255);
    }


}
