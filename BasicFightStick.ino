
#include "UnoJoy.h"

// Define our pins
int top_left = 8;
int top_mid = 10;
int top_right = 12;
int bot_left = 7;
int bot_mid = 5;
int bot_right = 3;


int LeftPin = 19;
int UpPin = 17;
int RightPin = 16;
int DownPin = 14;

void setup(){
  setupPins();
  setupUnoJoy();
}

void loop(){
  // Always be getting fresh data
  dataForController_t controllerData = getControllerData();
  setControllerData(controllerData);
}

void setupPins(void){
  // Set all the digital pins as inputs
  // with the pull-up enabled, except for the 
  // two serial line pins
  pinMode(12, INPUT);
  pinMode(10, INPUT);
  pinMode(8, INPUT);
  pinMode(7, INPUT);
  pinMode(5, INPUT);
  pinMode(3, INPUT);

  pinMode(19, INPUT);
  pinMode(17, INPUT);
  pinMode(16, INPUT);
  pinMode(14, INPUT);  
}

dataForController_t getControllerData(void){
  
  // Set up a place for our controller data
  //  Use the getBlankDataForController() function, since
  //  just declaring a fresh dataForController_t tends
  //  to get you one filled with junk from other, random
  //  values that were in those memory locations before
  dataForController_t controllerData = getBlankDataForController();
  // Since our buttons are all held high and
  //  pulled low when pressed, we use the "!"
  //  operator to invert the readings from the pins
  controllerData.triangleOn = digitalRead(top_left);
  controllerData.circleOn = digitalRead(top_mid);
  controllerData.squareOn = digitalRead(bot_left);
  controllerData.crossOn = digitalRead(bot_mid);
  controllerData.dpadUpOn = digitalRead(UpPin);
  controllerData.dpadDownOn = digitalRead(DownPin);
  controllerData.dpadLeftOn = digitalRead(LeftPin);
  controllerData.dpadRightOn = digitalRead(RightPin);
  
  controllerData.startOn = digitalRead(top_right);
  controllerData.selectOn = digitalRead(bot_right);
  
  // And return the data!
  return controllerData;
}
