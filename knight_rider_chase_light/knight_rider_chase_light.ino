// pwm knight rider
// David Gamache

int redIndex = 0;
int yellowIndex = 1;
int greenIndex = 2;
// This is where each of the 3 LEDs are connected:
int leds[3] = {11,10,9};
int stepSize[3] = {10,10,10};
int brightness[3] = {240,140,20}; // How bright the LED is

void setup() 
{
  // This is setup code that is run only once at startup initialization.
  // All 3 digital pins used are outputs to drive the LEDs:
  
  pinMode(leds[redIndex], OUTPUT);
  pinMode(leds[yellowIndex], OUTPUT);
  pinMode(leds[greenIndex], OUTPUT);
}

void loop() {
  // This main code runs repeatedly:

  // Starting with the LED dim, gradually get brighter
  analogWrite(leds[redIndex], brightness[redIndex]);  // Do the PWM instructed
  analogWrite(leds[yellowIndex], brightness[yellowIndex]);  // Do the PWM instructed
  analogWrite(leds[greenIndex], brightness[greenIndex]);  // Do the PWM instructed
  delay(40);  // Small delay
  // Set the next brightness
  if ((brightness[redIndex] == 10) || (brightness[redIndex] == 250)){
    stepSize[redIndex] = -stepSize[redIndex];
  }
  if ((brightness[yellowIndex] == 10) || (brightness[yellowIndex] == 250)){
    stepSize[yellowIndex] = -stepSize[yellowIndex];
  }
  if ((brightness[greenIndex] == 10) || (brightness[greenIndex] == 250)){
    stepSize[greenIndex] = -stepSize[greenIndex];
  }
  brightness[redIndex] += stepSize[redIndex];
  brightness[yellowIndex] += stepSize[yellowIndex];
  brightness[greenIndex] += stepSize[greenIndex];
}
