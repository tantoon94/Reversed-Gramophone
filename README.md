# CASA0016 - Reversed Gramophone - ReadMe File 

## What is the Reversed Gramophone?

This device is an experimental project aiming to visualise sound physically in real-time. Although various software exists that visualizes sound using digital tools and algorithms, it has been a challenge to materialize the effect of sound and make it visible without using a digital screen. Many artists and technicians have stemmed projects with the same goal. An example would be the experiments with salt and water to make sound visible through cymatics. However, the momentary nature of the sound made capturing a continuous sound like a music peace difficult. Therefore, this project was introduced to capture not only the momentary notes and pitches of the sound in real-time but also to visualise the recorded waves on a histogram that could show the overall look of the sound in time. 

## Components

1. Arduino Board (Arduino Uno)
2. Microphone Sound Sensor (MAX4466)
3. 180 Degree Servo (SG90)
4. Rotary Servo Motor (LEGO 360 Continuous Servo)
5. Adafruit NeoPixel LED Strip (8 LEDs)
6. Push Button (Picade Power Button)
7. Resistors (10kΩ for the button)
8. Breadboard (for prototyping)
9. Jumper Wires (male-to-male and male-to-female)
10 Power Supply (5V power supply is sufficient, Barrel Jack)
11. Capacitors (for noise filtering and avoiding servo jittering)

## Libraries
Make sure to include the following libraries in your Arduino IDE:

1. Servo.h
2. Adafruit_NeoPixel.h 
3. ArduinoFFT.h

## Setup Instructions
Connect the microphone sound sensor to the Arduino: A0
Connect the linear servo motor to the Arduino: Pin 9
Connect the rotary servo motor to the Arduino: Pin 10
Connect the NeoPixel LED strip to the Arduino: Pin 5
Connect the push button to the Arduino: Pin 2 (Use a pull-up resistor (10kΩ) between pin 2 and 5V)
Upload the provided Arduino code to your board.

### The Design 

## How to install

### Results

The device works by pressing an illuminated push button. while pushed, a green LED light turns on indicating the active recording. Meanwhile, the disc begins to rotate steadily via a continuous 360-degree servo and the microphone will input the recorded sound as a value between 500-900 (out of a possible 0-1023) to the Arduino. After processing the sound and extracting the amplitude value, it will be mapped to an angle of 0-180 that will drive a 180-degree servo attached to a linear gear holding the pen making it move linearly drawing on the rotary canvas. When the button is released, the LED light will go off and so will the servos and the result of the recorded sound will be a circular shape drawn on a removable disc. 

### Hindrances & Issues

1. The noise the servos produce could affect the microphone's input. 
2. The pin can record only one feature of the sound (amplitude) and not different frequency levels.
3. The design of the pin holder is not flexible making it difficult to remove and replace the disc.
4. The screw for the lid of the disc holder base does not entirely fit when printed out. 

## Further Developments
How can the servo noise issues be fixed? 
  - You can adjust the sensitivity of the microphone by turning the small screw located in the back of the sensor counterclockwise.
  - You can use capacitors in parallel to the microphone to smooth out the noise
  - Alternatively, you can adjust the threshold of the microphone's input in the Arduino code
What are the features that could be improved? How can they be improved?
  - The location of the microphone in the design is not ideal for recording sound. It could be placed in an isolated compartment on top of the device. Alternatively, the microphone could be separated entirely from the device and connected to it through a wireless network connection. 
What are the missing features?
  - The current version of this device only records one parameter of sound, the amplitude. Using multiple pins capturing different frequencies can help develop the device further in future versions.


##  Contact Details

Tina Samie: tina.samie.19@ucl.ac.uk
