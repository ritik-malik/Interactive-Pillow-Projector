#include <AltSoftSerial.h>
AltSoftSerial BTserial; 

int EN_A = 11;      //Enable pin for first motor
int IN1 = 5;       //control pin for first motor
int IN2 = 4;       //control pin for first motor
int IN3 = 7;        //control pin for second motor
int IN4 = 6;        //control pin for second motor
int EN_B = 10;      //Enable pin for second motor
 
// Change DEBUG to true to output debug information to the serial monitor
boolean DEBUG = true;
 
// Variables used for incoming data
  
const byte maxDataLength = 20;          // maxDataLength is the maximum length allowed for received data.
char receivedChars[maxDataLength+1] ;
boolean newData = false;               // newData is used to determine if there is a new command
String s = "";
 
 
void setup()  
{
    pinMode(EN_A, OUTPUT);
    pinMode(IN1, OUTPUT);  
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);  
    pinMode(IN4, OUTPUT);
    pinMode(EN_B, OUTPUT); 
 
    if (DEBUG)
    {
        // open serial communication for debugging and show the sketch name and the date compiled
        Serial.begin(9600);
        Serial.println(__FILE__);
        Serial.println(__DATE__);
        Serial.println(" ");
    }
 
    //  open software serial connection to the Bluetooth module.
    BTserial.begin(9600); 
    if (DEBUG)  {   Serial.println(F("AltSoftSerial started at 9600"));     }
 
    newData = false;
 
}
 
 
 
void loop()  
{
         recvWithStartEndMarkers();                // check to see if we have received any new commands
         if (newData)  {   processCommand();  }    // if we have a new command do something
         delay(30);
}
 
 
void processCommand()
{
    char current[sizeof(s)];
    s.toCharArray(current , sizeof(current));
    
    newData = false;
    if (DEBUG)  {   Serial.print("recieved data = ");  Serial.println(receivedChars);         }
    
    if (strcmp(receivedChars, current) != 0){
    if      (strcmp ("LEFT",receivedChars) == 0)  { 
      digitalWrite(IN1, HIGH);            // middle to left
      digitalWrite(IN2, LOW);             
      analogWrite(EN_A, 750);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(EN_B,185);
      delay(115);
      
      digitalWrite(IN1, LOW);          // 1 sec gap         
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      s = "LEFT";
      }
    else if (strcmp ("MFL",receivedChars) == 0) { 
      digitalWrite(IN1, LOW);               // left to middle
      digitalWrite(IN2, HIGH);
      analogWrite(EN_A, 750);
      digitalWrite(IN3, LOW);           
      digitalWrite(IN4, HIGH);
      analogWrite(EN_B,185);
      delay(115);

      digitalWrite(IN1, LOW);           // 1 sec gap
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      s = "MFL";
     }
    else if (strcmp ("MFR",receivedChars) == 0) { 
      digitalWrite(IN1, HIGH);          //right to middle
      digitalWrite(IN2, LOW);             
      analogWrite(EN_A, 750);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(EN_B,185);
      delay(115);
      
      digitalWrite(IN1, LOW);                   
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      s = "MFR";
    }
    else if (strcmp ("RIGHT",receivedChars) == 0) { 
      digitalWrite(IN1, LOW);               // middle to right
      digitalWrite(IN2, HIGH);
      analogWrite(EN_A, 750);
      digitalWrite(IN3, LOW);           
      digitalWrite(IN4, HIGH);
      analogWrite(EN_B,185);
      delay(115);
  
      digitalWrite(IN1, LOW);           // 1 sec gap
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      s = "RIGHT";
      }
      Serial.println(s);
    }
    delay(500);
}
 

void recvWithStartEndMarkers() 
{
     static boolean recvInProgress = false;
     static byte ndx = 0;
     char startMarker = '<';
     char endMarker = '>';
 
     if (BTserial.available() > 0) 
     {
          char rc = BTserial.read();
          if (recvInProgress == true) 
          {
               if (rc != endMarker) 
               {
                    if (ndx < maxDataLength) { receivedChars[ndx] = rc; ndx++;  }
               }
               else 
               {
                     receivedChars[ndx] = '\0'; // terminate the string
                     recvInProgress = false;
                     ndx = 0;
                     newData = true;
               }
          }
          else if (rc == startMarker) { recvInProgress = true; delay(100);}
     }
 
}
