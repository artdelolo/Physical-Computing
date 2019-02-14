int button1 = 2;
int led1 = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(button1, INPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:'
  int button = digitalRead(button1);
  Serial.print("button1: ");
   Serial.println(button);
    digitalWrite(led1, button);

}
