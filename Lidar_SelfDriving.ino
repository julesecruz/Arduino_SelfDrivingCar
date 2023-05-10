//LIDAR code 
#include <Wire.h>
#include <LIDARLite.h>
#include <Servo.h>
#include <SPI.h>

// Globals
LIDARLite lidarLite;
int cal_cnt = 0;
int rotation = 0;
Servo myservo;
int dist[9] ;
// FLIP LEFT AND RIGHT
//LIDAR STARTS FROM RIGHT AT 0 degrees if you are the car
//LIDAR 180 is full left

//dist[0] is far right, whichi s 0 degrees.
//dist[8] is far left, which is 180 degrees

void setup()
{

  Serial.begin(9600); // Initialize serial connection to display distance readings

  lidarLite.begin(0, true); // Set configuration to default and I2C to 400 kHz
  lidarLite.configure(0); // Change this number to try out alternate configurations
  myservo.attach(9); // attach the servo to our servo object

  myservo.write(90);
}
// rotates and collects data from the lidar
void loop()
{
forward();
updateLidar();
}

void forward(){
  
}
void reverse(){
  
}
void turnRight(){
  
}
void turnLeft(){
  
}
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
