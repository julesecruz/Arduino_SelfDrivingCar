#define WheelCW 7 //Wheel CW is defined as pin #7//

#define WheelCCW 8 //Wheel CCW is defined as pin #8//

#define SteeringCW 3

#define SteeringCCW 4

void setup() { 

  pinMode(WheelCW, OUTPUT); //Set CW as an output//
  
  pinMode(WheelCCW, OUTPUT); //Set CCW as an output//

  pinMode(SteeringCW,OUTPUT);
  pinMode(SteeringCCW,OUTPUT);
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



//STEERING MOTOR CLOCKWISE 
  steeringMotorCW();
  delay(1000);

//STEERING MOTOR OFF
  steeringMotorOff();
  delay(1000);


//STEERING MOTOR COUNTER CLOCKWISE
  steeringMotorCCW();
   delay(1000);

//STEERING MOTOR OFF

  steeringMotorOff();
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


void steeringMotorCCW(){
  digitalWrite(SteeringCW,HIGH);
  digitalWrite(SteeringCCW, LOW);
}

void steeringMotorOff(){
  digitalWrite(SteeringCW,LOW);
  digitalWrite(SteeringCCW, LOW);

  //delay(1000);
}
void steeringMotorCW(){
  digitalWrite(SteeringCW, LOW);
  digitalWrite(SteeringCCW, HIGH);
}
//end of code//
