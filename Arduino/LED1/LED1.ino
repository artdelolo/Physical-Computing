int button1 = 2;
int led1 = 12;
int led2 = 13;
int switchRead;

int counter = 0;

bool wasPressed = false;

long prevMillis = 0;
int interval = 1000;
boolean trigger = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(button1, INPUT);

  Serial.begin(9600);

}

void loop() {
  
  // put your main code here, to run repeatedly:'
  
  int button = digitalRead(button1);
  
  Serial.print("button1: ");
   Serial.println(button);
   
   // digitalWrite(led1, HIGH);
   // digitalWrite(led2, HIGH);

    if(button == HIGH){

      //counter = counter+1;
      wasPressed = true;
      
    }

    if(button == LOW && wasPressed == true){
     
      wasPressed = false;

      counter = counter + 1;
    }
    
    Serial.println(counter);

    if(counter == 0){
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      counter = 0;s
    }
    else if(counter == 1){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
    }
    else if(counter == 2){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
    }
     else if(counter == 3){
      if(millis() - prevMillis >= interval){
        prevMillis = millis();
        if(trigger == false){
          trigger = true;
        }else{
          trigger = false;
        }
      }
      if(trigger = true){
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
      }
      else{
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
      }
    }
    
    else{
      counter = 0;
    }


}
