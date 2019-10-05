int sensoroutput0 = 0;
int sensoroutput1 = 1;
int sensoroutput2 = 2;

void setup()
{

Serial.begin(9600);

pinMode(0,INPUT);
pinMode(1,INPUT);
pinMode(2,INPUT);
}
void loop()
{

  
int value0 = analogRead(sensoroutput0);  // function to read analog voltage from sensor
int value1  = analogRead(sensoroutput1);  // function to read analog voltage from sensor
int value2 = analogRead(sensoroutput2);  // function to read analog voltage from sensor

Serial.print("Left ");
Serial.print(value0);
Serial.print(" Middle ");
Serial.print(value1);
Serial.print(" Right ");
Serial.print(value2);
Serial.print("    ");

if(value1 < 500 && value0 > 400)  {
  Serial.print(" LEFT ");  }


if(value0 > 400 && value1 > 500 || value1 > 500){

Serial.print(" MIDDLE ");  }
Serial.print(" ");  }

if(value1 < 300 && value2 > 500) {
  Serial.print(" RIGHT ");  }




if(value0 < 150 && value1 < 150 && value2 < 150)  {

  Serial.print("  NO ONE ");

}

}

Serial.println();
delay(200);
} 
