#include <Servo.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN 5
#define LED_COUNT 8
#define BUTTON_PIN 2
#define SOUND_SENSOR_PIN A0
#define LINEAR_SERVO_PIN 9
#define ROTARY_SERVO_PIN 10

Servo linearServo;
Servo rotaryServo;
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

const int numReadings = 10; // Number of readings to average
int readings[numReadings];  // Array to store readings
int readIndex = 0;          // Index of the current reading
int total = 0;              // Running total
int average = 0;            // Average value

int soundLevel = 0;
const int threshold = 300; // Adjust this value based on your sound sensor's sensitivity
unsigned long previousMillis = 0;
const long interval = 20; // 2 seconds
bool recording = false;

int previousAngle = -1; // Initialize with an invalid angle

void setup() {
  //linearServo.attach(LINEAR_SERVO_PIN);
  //rotaryServo.attach(ROTARY_SERVO_PIN);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  Serial.begin(9600);

  // Initialize all readings to 0
  for (int i = 0; i < numReadings; i++) {
    readings[i] = 0;
  }
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    recording = !recording;
    delay(500); // Debounce delay
    
    if (recording) {
      Serial.println("Recording started");
    } else {
      // Explicitly stop the servos
      rotaryServo.detach();
      Serial.println("Recording stopped, servos set to neutral positions");
    }
  }

  if (recording) {
    strip.fill(strip.Color(0, 255, 0), 0, LED_COUNT); // Turn on green LEDs
    strip.show();
    rotaryServo.attach(ROTARY_SERVO_PIN);
    rotaryServo.write(70); // Rotate the paper disc

    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      soundLevel = analogRead(SOUND_SENSOR_PIN);

      // Subtract the last reading
      total = total - readings[readIndex];
      // Read from the sensor
      readings[readIndex] = soundLevel;
      // Add the reading to the total
      total = total + readings[readIndex];
      // Advance to the next position in the array
      readIndex = readIndex + 1;

      // If we're at the end of the array, wrap around to the beginning
      if (readIndex >= numReadings) {
        readIndex = 0;
      }

      int angle = map(soundLevel, threshold, 400, 1, 179); // Map average sound level to servo angle

      // Ensure the angle is within the 0-180 range
      if (angle < 1) {
        angle = 1;
      } else if (angle > 179) {
        angle = 179;
      }

      // Move the servo only if the angle has changed
      if (angle != previousAngle) {
        linearServo.attach(LINEAR_SERVO_PIN);
        linearServo.write(angle);
        previousAngle = angle;

        // Print the results for debugging
        Serial.print("Sound Level: ");
        Serial.print(soundLevel);
        Serial.print(" -> Servo Angle: ");
        Serial.println(angle);
      }
    }
  } else {
    strip.clear(); // Turn off LEDs
    strip.show();
    linearServo.detach();
  }
}