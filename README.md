# CASA0016 - Reversed Gramophone - ReadMe File 

## What is the Reversed Gramophone?

This device is an experimental project aiming to visualise sound physically in real-time. Although various software exists that visualizes sound using digital tools and algorithms, it has been a challenge to materialize the effect of sound and make it visible without using a digital screen. Many artists and technicians have stemmed projects with the same goal. An example would be the experiments with salt and water to make sound visible through cymatics. However, the momentary nature of the sound made it difficult to capture a continuous sound like a music peace for instance. Therefore, this project was introduced to capture not only the momentary notes and pitches of the sound in real-time but also to visualise the recorded waves on a histogram that could show the overall look of the sound in time. 

## Concept & Value



##  Methodology 

### The Programming 
### The Design 

## How to install

### Results

The device works by pressing an illuminated push button. while pushed, a green LED light turns on indicating the active recording. Meanwhile, the disc begins to rotate on a steady pace via a continuous 360-degree servo and the microphone will input the recorded sound as a value between 500-900 (out of a possible 0-1023) to the Arduino. After processing the sound and extracting the amplitude value, it will then be mapped to an angle of 0-180 that will drive a 180-degree servo attached to a linear gear holding the pen making it move in a linear manner drawing on the rotary canvas. When the button is released, the LED light will go off and so will the servos and the result of the recorded sound will be a circular shape drawn on a removable disc. 

### Hindrances & Issues

1. The noise produced by the servos affects the input of the microphone. 
2. The pin can record only one feature of the sound (amplitude) and not different frequency levels. 

## Further Developements
How can the issues be fixed?
What are the features that could be improved? How can they be improved?
What are the missing features?


##  Contact Details

Tina Samie: tina.samie.19@ucl.ac.uk
