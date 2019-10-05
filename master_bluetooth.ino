#include <AltSoftSerial.h>
AltSoftSerial BTserial; 

int sensoroutput0 = A0;
int sensoroutput1 = A1;
int sensoroutput2 = A2;
 
// Change DEBUG to true to output debug information to the serial monitor
boolean DEBUG = true;
String s = "";
 
void setup()  
{
    if (DEBUG)
    {
        // open serial communication for debugging and show 
        // the sketch filename and the date compiled
        Serial.begin(9600);
        Serial.println(__FILE__);
        Serial.println(__DATE__);
        Serial.println(" ");
    }
 
    //  open software serial connection to the Bluetooth module.
    BTserial.begin(9600); 
    if (DEBUG)  {   Serial.println("BTserial started at 9600");     }

  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
 
} // void setup()
 
 
void loop()  
{
  int value0 = analogRead(sensoroutput0);  // function to read analog voltage from sensor
  int value1  = analogRead(sensoroutput1);  // function to read analog voltage from sensor
  int value2 = analogRead(sensoroutput2);  // function to read analog voltage from sensor

  char c[sizeof(s)];
  s.toCharArray(c, sizeof(c));
  
  if(value1 < 500 && value0 > 400){
     BTserial.println("<LEFT>");
     if (DEBUG) {Serial.println("LEFT");}
     s = "LEFT";
  }
  else if((value0 > 400 && value1 > 500 || value1 > 500) && strcmp(c, "LEFT")==0){
     BTserial.println("<MFL>");
     if (DEBUG) {Serial.println("MFL");}
  }
  else if((value0 > 400 && value1 > 500 || value1 > 500) && strcmp(c, "RIGHT")==0){
     BTserial.println("<MFR>");
     if (DEBUG) {Serial.println("MFR");}
  }
  else if(value1 < 300 && value2 > 500){
     BTserial.println("<RIGHT>");
     if (DEBUG) {Serial.println("RIGHT");}
     s = "RIGHT";
  }
    
  delay(500);
}
