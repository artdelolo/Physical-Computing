#include "pitches.h"  //add note library
 
//notes in the melody
int melody[]={NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};
 
//digital pin 12 has a button attached to it. Give it an name
int buttonPin= 9;
int soundPin= 12;
 
//note durations. 4=quarter note / 8=eighth note
int noteDurations[]={4, 8, 8, 4, 4, 4, 4, 4};

int led1 = 3;
int led2 = 4;
int led3 = 5;
int led4 = 6;
int led5 = 7;
int led6 = 8;
 
 
void setup(){
 
  //make the button's pin input
  pinMode(buttonPin, INPUT);
  pinMode(soundPin, OUTPUT);
}
 
 
void loop(){
 
  //read the input pin
  int buttonState = digitalRead(buttonPin);
 
  //if the button is pressed
  if (buttonState == 1){
 
    //iterate over the notes of the melody
         analogWrite(led1, 255);
         analogWrite(led2, 255);
         analogWrite(led3, 255);
         analogWrite(led4, 255);
         analogWrite(led5, 255);
         analogWrite(led6, 255);
    for (int thisNote=0; thisNote <8; thisNote++){
      
      //to calculate the note duration, take one second. Divided by the note type
      int noteDuration = 1000 / noteDurations [thisNote];
      tone(soundPin, melody [thisNote], noteDuration);
 
      //to distinguish the notes, set a minimum time between them
      //the note's duration +30% seems to work well
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
 
      //stop the tone playing
      noTone(soundPin);
    }
  }
    else if(buttonState == 0){
         analogWrite(led1, 0);
         analogWrite(led2, 0);
         analogWrite(led3, 0);
         analogWrite(led4, 0);
         analogWrite(led5, 0);
         analogWrite(led6, 0);
    }
    
  }
