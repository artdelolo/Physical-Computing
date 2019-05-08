
const byte SENSOR_PIN = A0; // connect TMP sensor to A0
const byte LED_1      = 2;  // connect LED 1 to 2
const byte LED_2      = 3;  // connect LED 2 to ~3
const byte LED_3      = 4;  // connect LED 3 to 4

const float BASE_TEMP = 24.0;

unsigned int sensor_val;

void setup() {
    Serial.begin(9600);

    for (byte pin = LED_1; pin <= LED_3; pin++) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }
}

void loop() {
    // read & print temperature value
    sensor_val = analogRead(SENSOR_PIN);
    Serial.print("Sensor value: ");
    Serial.println(sensor_val);

    // map & print temperature value to voltage
    float voltage = (sensor_val / 1024.0) * 5.0;
    Serial.print("Volts: ");
    Serial.println(voltage);

    // from voltage, define temperature
    float temperature = (voltage - 0.5) * 100;
    Serial.print("Degrees C: ");
    Serial.println(temperature);
    Serial.println();

    // from temperature, indicate the LEDs
    if ((temperature >= BASE_TEMP)
            && (temperature < BASE_TEMP + 2)) {
        digitalWrite(LED_1, HIGH);
        digitalWrite(LED_2, HIGH); // level 1: all LEDs turned on
        digitalWrite(LED_3, HIGH);
    } else if (temperature < BASE_TEMP) {
        digitalWrite(LED_1, LOW);
        digitalWrite(LED_2, LOW); // level 0: all LEDs turned off
        digitalWrite(LED_3, LOW);
    } else if ((temperature >= BASE_TEMP + 2)
               && (temperature < BASE_TEMP + 4)) {
        digitalWrite(LED_1, HIGH);
        digitalWrite(LED_2, LOW); // level 2: LED_1 turned on, LEDs 2 & 3 turned off
        digitalWrite(LED_3, LOW);
    } else if ((temperature >= BASE_TEMP + 4)
               && (temperature < BASE_TEMP + 6)) {
        digitalWrite(LED_1, LOW);
        digitalWrite(LED_2, HIGH); // level 3: LED_2 turned on, LEDs 1 & 3 turned off
        digitalWrite(LED_3, LOW);
    } else {
        digitalWrite(LED_1, LOW);
        digitalWrite(LED_2, LOW); // level 4: LED 3 turned on, LEDs 1 & 2 turned off
        digitalWrite(LED_3, HIGH);
    }
}\
