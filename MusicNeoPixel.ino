//************
//Sound Level to light show sketch for the
//autogain microphone Amplifier from Adafruit on pin AO
//plus neopixel led functions (pin 6) mapped on to different sound levels to give music to light effects
//
//*************

//lines below set variables for neopixels

#include <Adafruit_NeoPixel.h>

#define NUMBER_PIXEL 406
#define LEDPIN    4

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMBER_PIXEL, LEDPIN, NEO_GRB + NEO_KHZ800);

int lng = 10;//long delay
int sht = 5;//short delay
int k; //counter

//lines below are for the microphone sampling from Adafruit autogain mic

const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

byte eyeWidth = floor(NUMBER_PIXEL/24);
byte middle = floor(NUMBER_PIXEL/2);

void setup()
{
  strip.begin();//initialises neopixels
  strip.setBrightness(127);// set brightness from 0 to max is 127
  strip.show();//clears any previous data in the strip
  //Serial.begin(9600);//set up for checking mic is working
}


void loop()
{
  //open void loop
  //first run the sound sampling
  unsigned long startMillis = millis(); // Start of sample window
  unsigned int peakToPeak = 0;   // peak-to-peak level

  unsigned int signalMax = 0;
  unsigned int signalMin = 1023;

  // collect data for 50 mS
  while (millis() - startMillis < sampleWindow)
  {
    //open while loop
    sample = analogRead(2);
    if (sample < 1024)  // toss out spurious readings
    {
      //open 1st if loop in while
      if (sample > signalMax)
      {
        //open 2nd if
        signalMax = sample;  // save just the max levels
      }//close 2nd if
      else if (sample < signalMin)
      {
        //open 3rd if
        signalMin = sample;  // save just the min levels
      }//close 3rd if
    }//close 1st if
  }//close while loop
  peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
  double volts = (peakToPeak * 3.3) / 1023;  // convert to volts

//section below maps the signal from the microphone on to 12 options for LED effects

  int sound = (volts * 10);

  int soundLevel = map(sound, 1, 10, 0, 11);
  //Serial.print("The volt level is  ");
  //Serial.println(volts);//for debugging

//next section is a series of 12 (0-11) 'if' statements which trigger different patterns.
//it is a combination of a traditional VU style meter fill of the strip
// combined with randomised animated patterns to keep it interesting
  if (soundLevel == 0)
  {
    //open if 0. When there is silence a rainbow pattern runs

    rainbowCycle(3);//from the neopixel library
    strip.show();

  }//close if 0 statement

  if (soundLevel == 1)
  {
    //open level 1 if statement which contains 4 randomised options

    int level1Color = random(1, 4);//choose random number 1 - 4

    if (level1Color == 1) //if random no 1 chosen light up pixels 1 and 2 red:
    {

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}    
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}    
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}   
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}    
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}    
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}    
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}    
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}   
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}    
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}   
      delay(lng);
    }//close red random no. 1

    else if (level1Color == 2) //if random no 2 choses show green
    {
      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close random no. 2 green

    else if (level1Color == 3) //run blue
    {

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close blue

    else if (level1Color == 4) //run yellow
    {

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close yellow



  }//end of if sound level 1 options


  if (soundLevel == 2)
  {
    //open level 2

    int level2Color = random(1, 5);//choose one of 5 options if sound level 2

    if (level2Color == 1) //run red mix
    {

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 1 red

    else if (level2Color == 2) //run green mix
    {
      //open option 2

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 206, 209);  strip.setPixelColor(2*middle - k, 0, 206, 209);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 206, 209);  strip.setPixelColor(2*middle - k, 0, 206, 209);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 206, 209);  strip.setPixelColor(2*middle - k, 0, 206, 209);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close green

    else if (level2Color == 3) //run blue mix
    {
      //open option 3

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 3 blue

    else if (level2Color == 4) //run yellow
    {
      //open option 4

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close yellow

    else if (level2Color == 5)//for a bit of variation 1 in 5 of level 2 will show a pattern across whole strip:
    {
      //open if 5
      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 200, 75, 109);   strip.setPixelColor(2*middle - k, 200, 75, 109);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 252, 203, 198);  strip.setPixelColor(2*middle - k, 252, 203, 198);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 216, 209);  strip.setPixelColor(2*middle - k, 255, 216, 209);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 253, 215, 130);  strip.setPixelColor(2*middle - k, 253, 215, 130);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 181, 198, 130);  strip.setPixelColor(2*middle - k, 181, 198, 130);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 141, 189, 193);  strip.setPixelColor(2*middle - k, 141, 189, 193);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 177, 217, 242);  strip.setPixelColor(2*middle - k, 177, 217, 242);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 100, 165, 187);  strip.setPixelColor(2*middle - k, 100, 165, 187);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 133, 105, 128);  strip.setPixelColor(2*middle - k, 133, 105, 128);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 140, 166, 95);   strip.setPixelColor(2*middle - k, 140, 166, 95);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 198, 44, 58);    strip.setPixelColor(2*middle - k, 198, 44, 58);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 149, 69, 103);   strip.setPixelColor(2*middle - k, 149, 69, 103);}  

      strip.show();
      delay(lng);

      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 200, 75, 109);   strip.setPixelColor(2*middle - k, 200, 75, 109);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 252, 203, 198);  strip.setPixelColor(2*middle - k, 252, 203, 198);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 216, 209);  strip.setPixelColor(2*middle - k, 255, 216, 209);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 253, 215, 130);  strip.setPixelColor(2*middle - k, 253, 215, 130);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 181, 198, 130);  strip.setPixelColor(2*middle - k, 181, 198, 130);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 141, 189, 193);  strip.setPixelColor(2*middle - k, 141, 189, 193);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 177, 217, 242);  strip.setPixelColor(2*middle - k, 177, 217, 242);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 100, 165, 187);  strip.setPixelColor(2*middle - k, 100, 165, 187);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 133, 105, 128);  strip.setPixelColor(2*middle - k, 133, 105, 128);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 140, 166, 95);   strip.setPixelColor(2*middle - k, 140, 166, 95);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 198, 44, 58);    strip.setPixelColor(2*middle - k, 198, 44, 58);}  
      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 149, 69, 103);   strip.setPixelColor(2*middle - k, 149, 69, 103);}  

      strip.show();
      delay(lng);

    }//close of option 5
  }//close level 2

  if (soundLevel == 3)
  {
    //open if sound level 3
    int level3Color = random(1, 5);

    if (level3Color == 1) //run red
    {
      //open option 1

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 1 red

    else if (level3Color == 2) //run green
    {
      //open option 2

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 245, 116, 97);  strip.setPixelColor(2*middle - k, 245, 116, 97);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 169, 221, 20);  strip.setPixelColor(2*middle - k, 169, 221, 20);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 245, 116, 97);  strip.setPixelColor(2*middle - k, 245, 116, 97);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 169, 221, 20);  strip.setPixelColor(2*middle - k, 169, 221, 20);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);       strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);       strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);       strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);       strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);       strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);       strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);       strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);       strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 2green

    else if (level3Color == 3) //run blue
    {
      //open option 3

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 169, 221, 199); strip.setPixelColor(2*middle - k, 169, 221, 199);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 245, 116, 97);  strip.setPixelColor(2*middle - k, 245, 116, 97);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 169, 221, 199); strip.setPixelColor(2*middle - k, 169, 221, 199);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 245, 116, 97);  strip.setPixelColor(2*middle - k, 245, 116, 97);}
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);       strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);       strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);       strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);       strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);       strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);       strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);       strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);       strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 3 blue

    else if (level3Color == 4) //run yellow
    {
      //open option 4

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 4 yellow

    else if (level3Color == 5)
    {
      //open option 5
      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 255, 105, 180);  strip.setPixelColor(2*middle - k, 255, 105, 180);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 105, 180);  strip.setPixelColor(2*middle - k, 255, 105, 180);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 255, 105, 180);  strip.setPixelColor(2*middle - k, 255, 105, 180);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 255, 105, 180);  strip.setPixelColor(2*middle - k, 255, 105, 180);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 255, 105, 180);  strip.setPixelColor(2*middle - k, 255, 105, 180);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 255, 105, 180);  strip.setPixelColor(2*middle - k, 255, 105, 180);}  
      strip.show();
      delay(sht);
    }//close of option 5
  }//close level 3


  if (soundLevel == 4)
  {
    //open if sound level 4
    int level4Color = random(1, 5);

    if (level4Color == 1) //run red
    {
      //open option 1

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close red

    else if (level4Color == 2) //run green
    {
      //open option 2

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close green

    else if (level4Color == 3) //run blue
    {
      //open option 3

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close blue

    else if (level4Color == 4) //run yellow
    {
      //open option 4

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close yellow

    else if (level4Color == 5)
    {
      ////open option 5
      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 01, 165);   strip.setPixelColor(2*middle - k, 255, 01, 165);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 255, 187, 218);  strip.setPixelColor(2*middle - k, 255, 187, 218);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 228, 194, 191);  strip.setPixelColor(2*middle - k, 228, 194, 191);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 153, 87, 205);   strip.setPixelColor(2*middle - k, 153, 87, 205);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 176, 284, 218);  strip.setPixelColor(2*middle - k, 176, 284, 218);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 67, 142, 200);   strip.setPixelColor(2*middle - k, 67, 142, 200);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 107, 167, 214);  strip.setPixelColor(2*middle - k, 107, 167, 214);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 168, 204, 232);  strip.setPixelColor(2*middle - k, 168, 204, 232);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 59, 198, 182);   strip.setPixelColor(2*middle - k, 59, 198, 182);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 100, 212, 199);  strip.setPixelColor(2*middle - k, 100, 212, 199);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 164, 231, 223);  strip.setPixelColor(2*middle - k, 164, 231, 223);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 176, 124, 218);  strip.setPixelColor(2*middle - k, 176, 124, 218);}  
      strip.show();
      delay(lng);
    }//close option 5

  }//close if sound level 4

  else if (soundLevel == 5)
  {
    //open if sound level 5


    int level5Color = random(1, 6);

    if (level5Color == 1) //run red
    {
      //open option 1

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);      strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);      strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);      strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);      strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);        strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);        strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);        strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);        strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);        strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);        strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 1 red

    else if (level5Color == 2) //run green
    {
      //open option 2

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 2 green

    else if (level5Color == 3) //run blue
    {
      //open option 3

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 3 blue

    else if (level5Color == 4) //run yellow
    {
      //open option 4

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close yellow

    else if (level5Color == 5)
    {
      //open option 5

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}       
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      strip.show();
      delay(lng);
    }//close option 5

    else if (level5Color == 6)
    {
      //open option 6

      //colorWipe(strip.Color(255, 0, 255), 5); // magenta
      //colorWipe(strip.Color(0, 255, 0), 5); // green
      strip.show();
    }//close option 6
  }//close if sound level 5


  else if (soundLevel == 6)
  {
    //open if soundlevel 6

    int level6Color = random(1, 6);

    if (level6Color == 1) //run red
    {
      //open option 1

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);       strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);   strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);       strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);       strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);   strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);       strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);       strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);         strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);         strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);         strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);         strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);         strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 1red

    else if (level6Color == 2) //run green
    {
      //open option 2

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 2 green

    else if (level6Color == 3) //run blue
    {
      //open option 3

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 3 blue

    else if (level6Color == 4) //run yellow
    {
      //open option 4

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 148, 0, 211);   strip.setPixelColor(2*middle - k, 148, 0, 211);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 75, 0, 130);    strip.setPixelColor(2*middle - k, 75, 0, 130);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);     strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);     strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);   strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 255, 127, 0);   strip.setPixelColor(2*middle - k, 255, 127, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);     strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);       strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);       strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);       strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);       strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);       strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(sht);
    }//close yellow

    else if (level6Color == 5)
    {
      //open option 5
      //colorWipe(strip.Color(0, 0, 255), 5); // Blue
      //colorWipe(strip.Color(255, 255, 0), 5); // yellow
      strip.show();
    }//close option 5

    else if (level6Color == 6)
    {
      //open option6

      //theaterChase(strip.Color(200, 0, 0), 5); // Red
      strip.show();
      delay(lng);
    }//close option 6
  }//close if sound level 6

  else if (soundLevel == 7)
  {
    //open if sound level 7
    int level7Color = random(1, 7);

    if (level7Color == 1) //run red
    {
      //open option 1

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 1 red

    else if (level7Color == 2) //run green
    {
      //open option 2

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 2 green

    else if (level7Color == 3) //run blue
    {
      //open option 3

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 3 blue

    else if (level7Color == 4) //run yellow
    {
      //open option 4

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 4 yellow

    else if (level7Color == 5)
    {
      //open option 5
      //colorWipe(strip.Color(255, 20, 147), 5); // pink
      //colorWipe(strip.Color(0, 206, 209), 5); // turquoise
      strip.show();
      delay(lng);
    }//close option 5

    else if (level7Color == 6)
    {
      //open option 6

      //theaterChase(strip.Color(255, 20, 100), 5); // Red
      strip.show();
      delay(sht);
    }//close option 6

    else if (level7Color == 7)
    {
      //open option 7
      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 70, 70);   strip.setPixelColor(2*middle - k, 0, 70, 70);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 100, 0);   strip.setPixelColor(2*middle - k, 0, 100, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 70);  strip.setPixelColor(2*middle - k, 255, 0, 70);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 50, 0, 150);  strip.setPixelColor(2*middle - k, 50, 0, 150);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 70, 70);   strip.setPixelColor(2*middle - k, 0, 70, 70);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 100, 0);   strip.setPixelColor(2*middle - k, 0, 100, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 70);  strip.setPixelColor(2*middle - k, 255, 0, 70);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 50, 0, 150);  strip.setPixelColor(2*middle - k, 50, 0, 150);}    
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 70);  strip.setPixelColor(2*middle - k, 255, 0, 70);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 100, 0);   strip.setPixelColor(2*middle - k, 0, 100, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 255, 0, 70);  strip.setPixelColor(2*middle - k, 255, 0, 70);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 50, 0, 150);  strip.setPixelColor(2*middle - k, 50, 0, 150);}  

      strip.show();
      delay(sht);
    }//close option 7
  }//close if sound level 7

  else if (soundLevel == 8)
  {
    //open if sound level 8

    int level8Color = random(1, 8);

    if (level8Color == 1) //run red
    {
      //open option 1
      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 1 red

    else if (level8Color == 2) //run green/blue
    {
      //open option 2

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 2 green/blue

    else if (level8Color == 3) //run turquoise / blue
    {
      //open option 3

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 206, 255);   strip.setPixelColor(2*middle - k, 0, 206, 255);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);     strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 206, 255);   strip.setPixelColor(2*middle - k, 0, 206, 255);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);     strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 206, 255);   strip.setPixelColor(2*middle - k, 0, 206, 255);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);     strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 206, 255);   strip.setPixelColor(2*middle - k, 0, 206, 255);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);     strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 206, 255);   strip.setPixelColor(2*middle - k, 0, 206, 255);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);       strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);       strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);       strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 3 blue

    else if (level8Color == 4) //run yellow
    {
      //open option 4

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 4 yellow

    else if (level8Color == 5)
    {
      //open option 5
      //colorWipe(strip.Color(255, 20, 147), 2); // pink
      //colorWipe(strip.Color(0, 206, 209), 2); // turquoise
      strip.show();
    }//close option 5

    else if (level8Color == 6)
    {
      //open option 6

      //theaterChase(strip.Color(0, 206, 209), 5); // Red
      strip.show();
      delay(sht);
    }//close option 6

    else if (level8Color == 7)
    {
      //open option 7
      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 70, 70);  strip.setPixelColor(2*middle - k, 0, 70, 70);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 100, 0);  strip.setPixelColor(2*middle - k, 0, 100, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 70); strip.setPixelColor(2*middle - k, 255, 0, 70);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 50, 0, 150); strip.setPixelColor(2*middle - k, 50, 0, 150);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 70, 70);  strip.setPixelColor(2*middle - k, 0, 70, 70);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 100, 0);  strip.setPixelColor(2*middle - k, 0, 100, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 70); strip.setPixelColor(2*middle - k, 255, 0, 70);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 50, 0, 150); strip.setPixelColor(2*middle - k, 50, 0, 150);}    
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 70); strip.setPixelColor(2*middle - k, 255, 0, 70);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 100, 0);  strip.setPixelColor(2*middle - k, 0, 100, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 255, 0, 70); strip.setPixelColor(2*middle - k, 255, 0, 70);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 50, 0, 150); strip.setPixelColor(2*middle - k, 50, 0, 150);}  

      strip.show();
      delay(lng);

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 255);  strip.setPixelColor(2*middle - k, 0, 255, 255);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 255);  strip.setPixelColor(2*middle - k, 0, 255, 255);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 255);  strip.setPixelColor(2*middle - k, 0, 255, 255);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 255);  strip.setPixelColor(2*middle - k, 0, 255, 255);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);


    }//close option 7

  }//close if sound level 8

  else if (soundLevel == 9)
  {
    //open if sound level 9

    int level9Color = random(1, 8);

    if (level9Color == 1) //run red
    {
      //open option 1

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 1 red

    else if (level9Color == 2) //run green
    {
      //open option 2

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 2 green

    else if (level9Color == 3) //run blue
    {
      //open option 3
      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 255);  strip.setPixelColor(2*middle - k, 255, 0, 255);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);    strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 255);  strip.setPixelColor(2*middle - k, 255, 0, 255);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);    strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 255);  strip.setPixelColor(2*middle - k, 255, 0, 255);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);    strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 255);  strip.setPixelColor(2*middle - k, 255, 0, 255);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);    strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 255);  strip.setPixelColor(2*middle - k, 255, 0, 255);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 255);    strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 3blue

    else if (level9Color == 4) //run yellow
    {
      //open option 4

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 4 yellow

    else if (level9Color == 5)
    {
      //open option 5
      //colorWipe(strip.Color(255, 255, 255), 6); // white
      //colorWipe(strip.Color(0, 206, 209), 2); // turquoise
      strip.show();
    }//close option 5

    else if (level9Color == 6)
    {
      //open option 6

      //theaterChase(strip.Color(50, 190, 209), 5); // turquise
      strip.show();
      delay(lng);
    }//close option 6

    else if (level9Color == 7)
    {
      //open option 7
      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 70, 70);   strip.setPixelColor(2*middle - k, 0, 70, 70);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 100, 0);   strip.setPixelColor(2*middle - k, 0, 100, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 70);  strip.setPixelColor(2*middle - k, 255, 0, 70);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 50, 0, 150);  strip.setPixelColor(2*middle - k, 50, 0, 150);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 70, 70);   strip.setPixelColor(2*middle - k, 0, 70, 70);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 100, 0);   strip.setPixelColor(2*middle - k, 0, 100, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 70);  strip.setPixelColor(2*middle - k, 255, 0, 70);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 50, 0, 150);  strip.setPixelColor(2*middle - k, 50, 0, 150);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 70);  strip.setPixelColor(2*middle - k, 255, 0, 70);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 100, 0);   strip.setPixelColor(2*middle - k, 0, 100, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 255, 0, 70);  strip.setPixelColor(2*middle - k, 255, 0, 70);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 50, 0, 150);  strip.setPixelColor(2*middle - k, 50, 0, 150);}  

      strip.show();
      delay(lng);

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 255);  strip.setPixelColor(2*middle - k, 0, 255, 255);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 255);  strip.setPixelColor(2*middle - k, 0, 255, 255);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 255);  strip.setPixelColor(2*middle - k, 0, 255, 255);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 255);  strip.setPixelColor(2*middle - k, 0, 255, 255);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 50, 50);  strip.setPixelColor(2*middle - k, 255, 50, 50);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);    strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 50, 50);  strip.setPixelColor(2*middle - k, 255, 50, 50);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);    strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 50, 50);  strip.setPixelColor(2*middle - k, 255, 50, 50);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);    strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 255, 50, 50);  strip.setPixelColor(2*middle - k, 255, 50, 50);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);    strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 255, 50, 50);  strip.setPixelColor(2*middle - k, 255, 50, 50);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 255, 0, 0);    strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 255, 50, 50);  strip.setPixelColor(2*middle - k, 255, 50, 50);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 255);    strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      strip.show();

      delay(lng);


    }//close option 7

    else if (level9Color == 8)
    {
      //open option 8
      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);        strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);        strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);        strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);        strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);        strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);        strip.setPixelColor(2*middle - k, 0, 0, 0);}  

      strip.show();
      delay (lng);

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);        strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);        strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);        strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);        strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);        strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);        strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  

      strip.show();
      delay(lng);


    }//close option 9

  }//close if sound level 9

  else if (soundLevel == 10)

  {
    //open if sound Level 10

    int level10Color = random(1, 8);

    if (level10Color == 1) //run red
    {
      //open option 1

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 1 red

    else if (level10Color == 2) //run green
    {
      //open option 2

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);    strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 2 green

    else if (level10Color == 3) //run blue
    {
      //open option 3

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 206, 255);  strip.setPixelColor(2*middle - k, 0, 206, 255);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);    strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 206, 255);  strip.setPixelColor(2*middle - k, 0, 206, 255);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);    strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 206, 255);  strip.setPixelColor(2*middle - k, 0, 206, 255);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);    strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 206, 255);  strip.setPixelColor(2*middle - k, 0, 206, 255);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);    strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 206, 255);  strip.setPixelColor(2*middle - k, 0, 206, 255);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 255);    strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 206, 255);  strip.setPixelColor(2*middle - k, 0, 206, 255);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 3 blue

    else if (level10Color == 4) //run yellow
    {
      //open option 4

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 4 yellow

    else if (level10Color == 5)
    {
      //open option 5

      //colorWipe(strip.Color(200, 40, 147), 5); // pink
      //colorWipe(strip.Color(0, 206, 209), 2); // turquoise
      strip.show();
      delay(sht);
    }//close option 5

    else if (level10Color == 6)
    {
      //open option 6
      //theaterChase(strip.Color(0, 206, 209), 5);
      strip.show();
      delay(sht);
    }//close option 6

    else if (level10Color == 7)
    {
      //open option 7
      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 70, 70);   strip.setPixelColor(2*middle - k, 0, 70, 70);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 100, 0);   strip.setPixelColor(2*middle - k, 0, 100, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 70);  strip.setPixelColor(2*middle - k, 255, 0, 70);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 50, 0, 150);  strip.setPixelColor(2*middle - k, 50, 0, 150);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 70, 70);   strip.setPixelColor(2*middle - k, 0, 70, 70);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 100, 0);   strip.setPixelColor(2*middle - k, 0, 100, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 70);  strip.setPixelColor(2*middle - k, 255, 0, 70);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 50, 0, 150);  strip.setPixelColor(2*middle - k, 50, 0, 150);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 70);  strip.setPixelColor(2*middle - k, 255, 0, 70);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 100, 0);   strip.setPixelColor(2*middle - k, 0, 100, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 255, 0, 70);  strip.setPixelColor(2*middle - k, 255, 0, 70);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 50, 0, 150);  strip.setPixelColor(2*middle - k, 50, 0, 150);}  

      strip.show();
      delay(lng);

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 255);  strip.setPixelColor(2*middle - k, 0, 255, 255);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 255);  strip.setPixelColor(2*middle - k, 0, 255, 255);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 255);  strip.setPixelColor(2*middle - k, 0, 255, 255);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 255);  strip.setPixelColor(2*middle - k, 0, 255, 255);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      strip.show();
      delay(sht);

    }//close option 7

  }//close if sound level 10


  else if (soundLevel == 11)

  {
    //open if sound Level 11

    int level11Color = random(1, 8);

    if (level11Color == 1) //run red
    {
      //open option 1

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 255, 0, 0);  strip.setPixelColor(2*middle - k, 255, 0, 0);}  
      strip.show();
      delay(lng);
    }//close option 1 red

    else if (level11Color == 2) //run green
    {
      //open option 2

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 255, 0);  strip.setPixelColor(2*middle - k, 0, 255, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 255);  strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      strip.show();
      delay(lng);
    }//close option 2  green

    else if (level11Color == 3) //run blue
    {
      //open option 3

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 206, 255);  strip.setPixelColor(2*middle - k, 0, 206, 255);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);    strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 206, 255);  strip.setPixelColor(2*middle - k, 0, 206, 255);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);    strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 206, 255);  strip.setPixelColor(2*middle - k, 0, 206, 255);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);    strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 206, 255);  strip.setPixelColor(2*middle - k, 0, 206, 255);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 255);    strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 206, 255);  strip.setPixelColor(2*middle - k, 0, 206, 255);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 255);    strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 0, 206, 255);  strip.setPixelColor(2*middle - k, 0, 206, 255);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 255);    strip.setPixelColor(2*middle - k, 0, 0, 255);}  
      strip.show();
      delay(lng);
    }//close option 3 blue

    else if (level11Color == 4) //run yellow
    {
      //open option 4

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      strip.show();
      delay(lng);
    }//close option 4 yellow

    else if (level11Color == 5)
    {
      //open option 5

      //colorWipe(strip.Color(0, 40, 255), 5); // pink
      //colorWipe(strip.Color(0, 209, 206), 2); // turquoise
      strip.show();
      delay(sht);
    }//close option 5

    else if (level11Color == 6) //open option 6
    {
      //open option 6
      //theaterChase(strip.Color(0, 206, 109), 5);
      strip.show();
      delay(sht);
    }//close option 6

    else if (level11Color == 7)//open option 7
    {
      //open option 7
      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 70, 70);   strip.setPixelColor(2*middle - k, 0, 70, 70);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 100, 0);   strip.setPixelColor(2*middle - k, 0, 100, 0);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 70);  strip.setPixelColor(2*middle - k, 255, 0, 70);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 50, 0, 150);  strip.setPixelColor(2*middle - k, 50, 0, 150);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 0, 70, 70);   strip.setPixelColor(2*middle - k, 0, 70, 70);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 100, 0);   strip.setPixelColor(2*middle - k, 0, 100, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 70);  strip.setPixelColor(2*middle - k, 255, 0, 70);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 50, 0, 150);  strip.setPixelColor(2*middle - k, 50, 0, 150);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 255, 0, 70);  strip.setPixelColor(2*middle - k, 255, 0, 70);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 0, 100, 0);   strip.setPixelColor(2*middle - k, 0, 100, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 255, 0, 70);  strip.setPixelColor(2*middle - k, 255, 0, 70);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 50, 0, 150);  strip.setPixelColor(2*middle - k, 50, 0, 150);}  

      strip.show();
      delay(lng);

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 255);  strip.setPixelColor(2*middle - k, 0, 255, 255);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 255);  strip.setPixelColor(2*middle - k, 0, 255, 255);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 255);  strip.setPixelColor(2*middle - k, 0, 255, 255);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 255);  strip.setPixelColor(2*middle - k, 0, 255, 255);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 255, 255, 255);  strip.setPixelColor(2*middle - k, 255, 255, 255);}  
      strip.show();
      delay(lng);

      for(k = middle - 1 - 0*eyeWidth;  k >= middle - 1*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 255);  strip.setPixelColor(2*middle - k, 0, 255, 255);}  
      for(k = middle - 1 - 1*eyeWidth;  k >= middle - 2*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 255);  strip.setPixelColor(2*middle - k, 0, 255, 255);}  
      for(k = middle - 1 - 2*eyeWidth;  k >= middle - 3*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 3*eyeWidth;  k >= middle - 4*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 4*eyeWidth;  k >= middle - 5*eyeWidth; k--){         strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 5*eyeWidth;  k >= middle - 6*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 6*eyeWidth;  k >= middle - 7*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 255);  strip.setPixelColor(2*middle - k, 0, 255, 255);}  
      for(k = middle - 1 - 7*eyeWidth;  k >= middle - 8*eyeWidth; k--){         strip.setPixelColor(k, 0, 255, 255);  strip.setPixelColor(2*middle - k, 0, 255, 255);}  
      for(k = middle - 1 - 8*eyeWidth;  k >= middle - 9*eyeWidth; k--){         strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      for(k = middle - 1 - 9*eyeWidth;  k >= middle - 10*eyeWidth; k--){        strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 10*eyeWidth; k >= middle - 11*eyeWidth; k--){        strip.setPixelColor(k, 255, 255, 0);  strip.setPixelColor(2*middle - k, 255, 255, 0);}  
      for(k = middle - 1 - 11*eyeWidth; k >= middle - 12*eyeWidth; k--){        strip.setPixelColor(k, 0, 0, 0);      strip.setPixelColor(2*middle - k, 0, 0, 0);}  
      strip.show();
      delay(lng);

    }//close option 7

  }//close if sound level 11

}//close void loop()

//neopixel functions below



void colorWipe(uint32_t c, uint8_t wait)
{
  //open colorwipe
  for(uint16_t i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}//close colorWipe function

void theaterChase(uint32_t c, uint8_t wait)
{
  //open theaterchase function
  for (int j = 0; j < 3; j++) //do 3 cycles of chasing
  {
    for (int q = 0; q < 3; q++)
    {
      for (int i = 0; i < strip.numPixels(); i = i + 3)
      {
        strip.setPixelColor(i + q, c);  //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (int i = 0; i < strip.numPixels(); i = i + 3)
      {
        strip.setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
}//close theater chase function

void rainbowCycle(uint8_t wait)  //open rainbow function
{
  uint16_t i, j;

  for(j = 0; j < 256; j++) // 1 cycles of all colors on wheel
  {
    for(i = 0; i <= strip.numPixels(); i++)
    {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}//close rainbow function
//you need to included the code below for the neopixel functions that use the 'wheel' code:
uint32_t Wheel(byte WheelPos)
{
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85)
  {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170)
  {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
