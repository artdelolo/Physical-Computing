

int soundPin= 2;
 

int buttonGreen = 11;
int buttonRed = 10;

int buttonGreenLED = 13;
int buttonRedLED = 12;


int led1Green = 3;
int led1Red = 4;
int led2Green = 5;
int led2Red = 6;
int led3Green = 7;
int led3Red = 8;

int buttonStart = 9;


int counter = 140;

bool GreenWasPressed = false;
bool RedWasPressed = false;


long prevMillis = 0;
int interval = 1000;
boolean trigger = false;


void setup() {
  // put your setup code here, to run once:

    pinMode(led1Green,OUTPUT);
    pinMode(led2Green,OUTPUT);
    pinMode(led3Green,OUTPUT);
    pinMode(led1Red,OUTPUT);
    pinMode(led2Red,OUTPUT);
    pinMode(led3Red,OUTPUT);
    pinMode(buttonGreenLED,OUTPUT);
    pinMode(buttonRedLED,OUTPUT);
    pinMode(buttonGreen, INPUT);
    pinMode(buttonRed, INPUT);
    pinMode(soundPin, OUTPUT);

    Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
  int GreenButton = digitalRead(buttonGreen);
  int RedButton = digitalRead(buttonRed);


   if(GreenButton == LOW){

      GreenWasPressed = true;
      
    }

    if(GreenButton == HIGH && GreenWasPressed == true){
     
      GreenWasPressed = false;

      counter = counter + 10;
    }

   if(RedButton == LOW){

      RedWasPressed = true;
      
    }

    if(RedButton == HIGH && RedWasPressed == true){
     
      RedWasPressed = false;

      counter = counter - 10;
    }
 
 if(counter < 25){
   counter = 0;
         analogWrite(led1Red, 255);
         analogWrite(led2Red, 255);
         analogWrite(led3Red, 255);
         analogWrite(led1Green, 0);
         analogWrite(led2Green, 0);
         analogWrite(led3Green, 0);
            if(counter < -25){
             digitalWrite(buttonRedLED, HIGH);
              analogWrite(led1Red, 255);
               analogWrite(led2Red, 255);
              analogWrite(led3Red, 255);
              analogWrite(led1Green, 0);
               analogWrite(led2Green, 0);
                analogWrite(led3Green, 0);
               
            
            }
  
   }else if(counter >=25 && counter <=120){
         analogWrite(led1Red, 255);
         analogWrite(led2Red, 255);
         analogWrite(led3Green, 255);
         analogWrite(led1Green, 0);
         analogWrite(led2Green, 0);
         analogWrite(led3Red, 0);
         
     }else if(counter >120 && counter <=200){
         analogWrite(led1Red, 255);
         analogWrite(led2Red, 50);
         analogWrite(led2Green, 0);
         analogWrite(led3Green , 255);
          analogWrite(led1Green, 0);
          analogWrite(led3Red, 0);
         }else if(counter >200 && counter <=255){
         analogWrite(led1Red, 255);
         analogWrite(led2Green, 255);
         analogWrite(led3Green , 255);
         analogWrite(led1Green, 0);
         analogWrite(led2Red, 0);
         analogWrite(led3Red, 0);
         
    }else if(counter >255){
         //counter = 255;
         analogWrite(led1Green, 255);
         analogWrite(led2Green, 255);
         analogWrite(led3Green, 255);
         analogWrite(led1Red, 0);
         analogWrite(led2Red, 0);
         analogWrite(led3Red, 0);
         
         if(counter > 275){
          digitalWrite(buttonGreenLED, HIGH);
          analogWrite(led1Green, 255);
          analogWrite(led2Green, 255);
          analogWrite(led3Green, 255);
          analogWrite(led1Red, 0);
          analogWrite(led2Red, 0);
          analogWrite(led3Red, 0);

        
    
    }
    }
    }
   
    //analogWrite(led1,255);
    //analogWrite(led2,255);
    //analogWrite(led3,255);


   /*if(GreenButton == LOW){

        Serial.print("Green BUTTON: ");
        Serial.println(GreenButton);
        digitalWrite(buttonGreenLED, HIGH);
        }

    if(RedButton == LOW){

        Serial.print("Red BUTTON");
        Serial.println(RedButton);
        digitalWrite(buttonRedLED, HIGH);
    }
    if (GreenButton == HIGH && RedButton == HIGH) {
      Serial.println("NO Green");
      digitalWrite(buttonGreenLED, LOW);
      digitalWrite(buttonRedLED, LOW);
    }

   if (resetButton == HIGH) {
      Serial.println("RESET");
    }
    */
                 
    
