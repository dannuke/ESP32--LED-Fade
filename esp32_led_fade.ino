

//credit :Peter Dalmaris Tech Explorations
const byte led_gpio = 32; //the PMW pin the LED is attached to
int brightness = 0; //how bright is the LED
int fadeAmount = 5; //how many points to fade the LED by

//the setup routine runs once when you press reset:
void setup () {
  ledcAttachPin(led_gpio,0); //assign a led pins to a channel

//intialize channels
//channels 0-15, rsoltion 1-16 bits, freq limits depend on resolution
//ledsSetup (uint8_t channel, uint32_t freq, uint8_t resolution resolution_bits);
ledcSetup(0,12000,8); // 12 kHz PMW, 8 bit resolution
 }

//the loop routine runs over and over again forever
void loop () {
  ledcWrite (0,brightness); //set the brightness of the led

  //change the brightness for the next time through the loop:
  brightness = brightness = fadeAmount;

  //reverse the direction of the fading at the end of the fade
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount= -fadeAmount;
  }
    
 //wait 30 milliseconds to see dimmimg effect
 delay (30);
}
