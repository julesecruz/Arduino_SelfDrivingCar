# Arduino_SelfDrivingCar
Arduino Based PowerWheels Self Driving Car

Converted PowerWheels into self-driving car using Arduino. Relies on Lidar for collision detection. 

STEP 1. Research 
Our first step was to go online and download the manual for the Power Wheel that we were modifying. 

STEP 2. Upgrade battery
Powerwheel batteries did not give us enough power. We upgraded to use Milwaukee Batteries and used this conversion kit. 
https://www.amazon.com/Adapter-Milwaukee-Conversion-UIInosoo-Robotics/dp/B09GJJLZCK/ref=sr_1_1_sspa?crid=1502F4O3CGHYP&keywords=18v+milwaukee+battery+to+wire+converter&qid=1675794078&sprefix=18v+milwaukee+battery+to+wires+converte%2Caps%2C106&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEzUjFORklJVk1VNE9HJmVuY3J5cHRlZElkPUEwOTAyNzUzMVAyNVJMOFpIUzlCUyZlbmNyeXB0ZWRBZElkPUEwNTk5Mzc3MTdMMTZTVkc1T0ZXQSZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU=

STEP 3. Upgrade wheels
We 3D printed new wheel parts and fitted them with these wheels. Make sure diamaters match wheels. 
https://www.amazon.com/AR-PRO-4-Pack-10-Inch-Rubber-Wheels/dp/B08YJLQP5G/ref=sr_1_1_sspa?crid=B1W2YPAKH0UW&keywords=power%2Bwheel%2Brubber%2Btires&qid=1676053236&sprefix=power%2Bwheel%2Brubber%2Btires%2Caps%2C158&sr=8-1-spons&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUExWUcwUzRKMllUU004JmVuY3J5cHRlZElkPUEwNjE2ODY4M0QzRTFNUEVUTVVHUiZlbmNyeXB0ZWRBZElkPUEwODAwOTQyMTk2M0ZOSUZBQlZEUSZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU&th=1

STEP 4. Wrire & code Lidar
  We used Lidar Lite V3. 
  https://learn.sparkfun.com/tutorials/lidar-lite-v3-hookup-guide/all

  We also placed the Lidar on a motor and coded it to rotate. 
  
STEP 5: Add an actuator (if no motor in front of car to control steering)
  https://arduinogetstarted.com/tutorials/arduino-actuator-with-feedback
  We bought this one
    https://www.amazon.com/PROGRESSIVE-AUTOMATIONS-Electric-Actuator-PA-14P-2-35/dp/B00Q74IBCC?&linkCode=sl1&tag=zlufy-20&linkId=f60dfedcdee35f68808c6b7d04ad09f0&language=en_US&ref_=as_li_ss_tl
  
  
Alternate Step 5: wire up front motor to an L298n motor driver and control with code for Arduino
  https://lastminuteengineers.com/l298n-dc-stepper-driver-arduino-tutorial/
  
  
 LED Lights:
  https://randomnerdtutorials.com/guide-for-ws2812b-addressable-rgb-led-strip-with-arduino/milwaulk
