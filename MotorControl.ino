#define WheelCW 7 //Wheel CW is defined as pin #7//

#define WheelCCW 8 //Wheel CCW is defined as pin #8//


void setup() { 

  pinMode(WheelCW, OUTPUT); //Set CW as an output//
  
  pinMode(WheelCCW, OUTPUT); //Set CCW as an output//

}

void loop() { //Loop runs forever//


//WHEEL MOTOR CLOCKWISE 
  wheelMotorCW();
  delay(1000);

//WHEEL MOTOR OFF
  wheelMotorOff();
  delay(1000);
  
//WHEEL MOTOR COUNTER CLOCKWISE
  wheelMotorCCW();
   delay(1000);

//WHEEL MOTOR OFF

  wheelMotorOff();
  delay(1000);




}

void wheelMotorCCW(){
  digitalWrite(WheelCW,HIGH);
  digitalWrite(WheelCCW, HIGH);
}

void wheelMotorOff(){
  digitalWrite(WheelCW,LOW);
  digitalWrite(WheelCCW, HIGH);
}
void wheelMotorCW(){
  digitalWrite(WheelCW, LOW);
  digitalWrite(WheelCCW, LOW);
}


//end of code//
