const int green_led_pin = 9;
 const int red_led_pin = 10;
 const int blue_led_pin = 11;

 const int red_sensor_pin = A0;
 const int green_sensor_pin = A1;
 const int blue_sensor_pin = A2;

 int red_value = 0;
 int blue_value = 0;
 int green_value = 0;

 int red_sensor_value = 0;
 int blue_sensor_value = 0;
 int green_sensor_value = 0;


void setup() 
{
 Serial.begin (9600);
 pinMode (green_led_pin, OUTPUT);  
 pinMode (red_led_pin, OUTPUT);  
 pinMode (blue_led_pin, OUTPUT);  
}

void loop()
{
int red_sensor_value = analogRead (red_sensor_pin);
delay (5);
int green_sensor_value = analogRead (green_sensor_pin);
delay (5);
int blue_sensor_value = analogRead (blue_sensor_pin);

Serial.print ("Raw sensor values:  \t red:  ");
Serial.print (red_sensor_value);
Serial.print ("\t green:  ");
Serial.print (green_sensor_value);
Serial.print ("\t blue:  ");
Serial.println (blue_sensor_value);

red_value = red_sensor_value / 4;
green_value = green_sensor_value / 4;
blue_value = blue_sensor_value / 4;

Serial.print ("Mapped sensor values:  \t red:  ");
Serial.print (red_value);
Serial.print ("\t green:  ");
Serial.print (green_value);
Serial.print ("\t blue:  ");
Serial.println (blue_value);

analogWrite (red_led_pin, red_value);
analogWrite (green_led_pin, green_value);
analogWrite (blue_led_pin, blue_value);
}
