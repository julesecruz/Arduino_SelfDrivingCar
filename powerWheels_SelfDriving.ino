//Code for Powerwheels using an actuator, lidar
#include <Wire.h>
#include <LIDARLite.h>
#include <Servo.h>
#include <SPI.h>

// Globals
int ENA_PIN  = 7; // the Arduino pin connected to the EN1 pin L298N
int IN1_PIN  = 6; // the Arduino pin connected to the IN1 pin L298N
int IN2_PIN  =5; // the Arduino pin connected to the IN2 pin L298N
//int POTENTIOMETER_PIN =0; // A0 // the Arduino pin connected to the potentiometer of the actuator
#define POTENTIOMETER_PIN   A0 

LIDARLite lidarLite;
int cal_cnt = 0;
int rotation = 0;
Servo myservo;
int dist[9] ;
// FLIP LEFT AND RIGHT
//LIDAR STARTS FROM RIGHT AT 0 degrees if you are the car
//LIDAR 180 is full left

//actuator max is 47, min is 471
int straightAct =  259;  // position of actuator to go straight
int leftAct =  47;  // position of actuator to go straight
int rightAct =  471;  // position of actuator to go straight
//dist[0] is far right, whichi s 0 degrees.
//dist[8] is far left, which is 180 degrees

void setup()
{

  Serial.begin(9600); // Initialize serial connection to display distance readings

  lidarLite.begin(0, true); // Set configuration to default and I2C to 400 kHz
  lidarLite.configure(0); // Change this number to try out alternate configurations
  myservo.attach(9); // attach the servo to our servo object

  myservo.write(90);

  pinMode(ENA_PIN, OUTPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);

  digitalWrite(ENA_PIN, HIGH);

}
// rotates and collects data from the lidar
void loop()
{
forward();
updateLidar();
}


/*--------------------------------------------------------ACTUATOR--------------------------------------------------------*/



void forward(){
    int potent = analogRead(POTENTIOMETER_PIN);
    while (potent < straightAct)
    {
       //too far left? go extend actuator
         digitalWrite(IN1_PIN, HIGH);
         digitalWrite(IN2_PIN, LOW);
         delay(100); 
    }
    
    while (potent > straightAct)
    {
       //too far right? go retract actuator
       digitalWrite(IN1_PIN, LOW);
       digitalWrite(IN2_PIN, HIGH);
       delay(100); // wait for actuator fully extends. It will stop retracting 
           
    }
    //make wheels rotate forward
}
void reverse(){
int potent = analogRead(POTENTIOMETER_PIN);
    while (potent < straightAct)
    {
       //too far left? go extend actuator
         digitalWrite(IN1_PIN, HIGH);
         digitalWrite(IN2_PIN, LOW);
         delay(100); 
    }
    
    while (potent > straightAct)
    {
       //too far right? go retract actuator
       digitalWrite(IN1_PIN, LOW);
       digitalWrite(IN2_PIN, HIGH);
       delay(100); // wait for actuator fully extends. It will stop retracting 
           
    }
    //make wheels rotate backwards
}
void turnRight(){
    int potent = analogRead(POTENTIOMETER_PIN);
    while (potent < straightAct)
    {
       //too far left? go extend actuator
         digitalWrite(IN1_PIN, HIGH);
         digitalWrite(IN2_PIN, LOW);
         delay(100); 
    }
    //turn the wheels right
}
void turnLeft(){
    int potent = analogRead(POTENTIOMETER_PIN);
    while (potent > straightAct)
    {
       //too far right? go retract actuator
       digitalWrite(IN1_PIN, LOW);
       digitalWrite(IN2_PIN, HIGH);
       delay(100); // wait for actuator fully extends. It will stop retracting 
           
    }
    // turn the wheels right
}



/*--------------------------------------------------------LIDAR--------------------------------------------------------*/



void updateLidar(){
  
 getDist();
}

void getDist(){
  
     
  for(int i = 0; i < 9; i++){
    dist[i]= (turnLidarLeft()+turnLidarLeft())/2;
  
    delay(25);
  } 
  for(int i = 0; i < 9; i++){
    dist[9-i-1]=(turnLidarRight()+turnLidarRight())/2;
    delay(25);
  }
}

// returns readings from the lidar
int lidar(){
  int dist;

  // At the beginning of every 100 readings,
  // take a measurement with receiver bias correction
  if ( cal_cnt == 0 ) {
    dist = lidarLite.distance();      // With bias correction
  } else {
    dist = lidarLite.distance(false); // Without bias correction
  }

  // Increment reading counter
  cal_cnt++;
  cal_cnt = cal_cnt % 100;


  delay(100);
  return dist;
}

int turnLidarRight(){
    int Dist = lidar();
    myservo.write(rotation);
    rotation -= 10;
    return(Dist);
}
int turnLidarLeft(){
    int Dist = lidar();
    myservo.write(rotation); 
    rotation += 10;
    return(Dist);
}
