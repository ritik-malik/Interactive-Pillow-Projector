
//Motor Pins
int EN_A = 11;      //Enable pin for first motor
int IN1 = 9;       //control pin for first motor
int IN2 = 8;       //control pin for first motor
int IN3 = 7;        //control pin for second motor
int IN4 = 6;        //control pin for second motor
int EN_B = 10;      //Enable pin for second motor


void setup ( ) {
  
  Serial.begin (9600); //Starting the serial communication at 9600 baud rate
  //Initializing the motor pins as output
  pinMode(EN_A, OUTPUT);
  pinMode(IN1, OUTPUT);  
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);  
  pinMode(IN4, OUTPUT);
  pinMode(EN_B, OUTPUT);
                     
}

void loop () {
  
    
digitalWrite(IN1, HIGH);            // right to middle
digitalWrite(IN2, LOW);             
analogWrite(EN_A,750);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);
analogWrite(EN_B,185);
delay(115);


    digitalWrite(IN1, LOW);          // 1 sec gap         
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
     delay(1000);



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
     delay(1000);

      
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
    delay(1000);

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
    delay(1000);
