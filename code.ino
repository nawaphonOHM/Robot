/* Control of line following robot
connection  
            pin12 SS1
            pin13 SS2
            pin2 SS3
            pin3 SS4
            pin4 SS5
            pin5 IN1
            pin6 IN2
            pin7 IN3
            pin8 IN4
            pin9 EnA left motor
            pin10 EnB right motor
            
left motor pin5 pin6
            H    L    Forward
            L    H    Backword
            L    L    Stop
right motor pin7 pin8
            H    L    Forward
            L    H    Backward
            L    L    Stop
*/
int SS1 = 12, SS2 = 13, SS3 = 2, SS4 = 3, SS5 = 4, IN1RolationLeft = 5, IN2RolationLeft = 6, IN1RolationRight = 7, IN2RolationRight = 8, 
EnLeftMotor = 9, EnRightMotor = 10;

void setup()
{
  Serial.begin(9600);
  pinMode(SS1, INPUT);
  pinMode(SS2, INPUT);
  pinMode(SS3, INPUT);
  pinMode(SS4, INPUT);
  pinMode(SS5, INPUT);
  pinMode(IN1RolationLeft, OUTPUT);
  pinMode(IN2RolationLeft, OUTPUT);
  pinMode(IN1RolationRight, OUTPUT);
  pinMode(IN2RolationRight, OUTPUT);
  pinMode(EnLeftMotor, OUTPUT);
  pinMode(EnRightMotor, OUTPUT);
  
  digitalWrite(IN1RolationLeft, LOW);
  digitalWrite(IN2RolationLeft, LOW);
  digitalWrite(IN1RolationRight, LOW);
  digitalWrite(IN2RolationRight, LOW);
  digitalWrite(EnLeftMotor, LOW);
  digitalWrite(EnRightMotor, LOW);
}
void loop()
{
  int Sensor1 = digitalRead(SS1), Sensor2 = digitalRead(SS2), Sensor3 = digitalRead(SS3), Sensor4 = digitalRead(SS4), 
            Sensor5 = digitalRead(SS5), pwm = 180;
  
  Serial.print(Sensor1);
  Serial.print(Sensor2);
  Serial.print(Sensor3);
  Serial.print(Sensor4);
  Serial.println(Sensor5);
  
  
  if(Sensor1 == LOW && Sensor2 == LOW && Sensor3 == LOW && Sensor4 == LOW && Sensor5 == LOW)
  {
    Stop(); 
  }
  else if(Sensor3 == LOW)
  {
    Forward(pwm);
  }
  else if(Sensor4 == LOW)
  {
    TurnRight(pwm);
  }
  else if(Sensor2 == LOW)
  {
    TurnLeft(pwm);
  }
  
}
void Forward(int speed)
{
  digitalWrite(IN1RolationLeft, HIGH);
  digitalWrite(IN2RolationLeft, LOW);
  analogWrite(EnLeftMotor, speed);
  
  digitalWrite(IN1RolationRight, HIGH);
  digitalWrite(IN2RolationRight, LOW);
  analogWrite(EnRightMotor, speed);
  
}
void Backward(int speed)
{
  digitalWrite(IN1RolationLeft, LOW);
  digitalWrite(IN2RolationLeft, HIGH);
  analogWrite(EnLeftMotor, speed);
  
  digitalWrite(IN1RolationRight, LOW);
  digitalWrite(IN2RolationRight, HIGH);
  analogWrite(EnRightMotor, speed);
  
}
void Stop()
{
   digitalWrite(IN1RolationLeft, LOW);
   digitalWrite(IN2RolationLeft, LOW);
   digitalWrite(IN1RolationRight, LOW);
   digitalWrite(IN2RolationRight, LOW);
}
void TurnLeft(int speed)
{
   digitalWrite(IN1RolationLeft, LOW);
   digitalWrite(IN2RolationLeft, LOW);
   analogWrite(EnLeftMotor, 0);
   
   digitalWrite(IN1RolationRight, HIGH);
   digitalWrite(IN2RolationRight, LOW);
   analogWrite(EnRightMotor, speed);
}

void TurnRight(int speed)
{
   digitalWrite(IN1RolationRight, LOW);
   digitalWrite(IN2RolationRight, LOW);
   analogWrite(EnRightMotor, 0);
   
   digitalWrite(IN1RolationLeft, HIGH);
   digitalWrite(IN2RolationLeft, LOW);
   analogWrite(EnLeftMotor, speed);
}
void RotateRight(int speed)
{
   digitalWrite(IN1RolationLeft, HIGH);
   digitalWrite(IN2RolationLeft, LOW);
   analogWrite(EnLeftMotor, speed);
   
   digitalWrite(IN1RolationRight, LOW);
   digitalWrite(IN2RolationRight, HIGH);
   analogWrite(EnRightMotor, speed);
}
void RotateLeft(int speed)
{
   digitalWrite(IN1RolationRight, HIGH);
   digitalWrite(IN2RolationRight, LOW);
   analogWrite(EnRightMotor, speed);
   
   digitalWrite(IN1RolationLeft, LOW);
   digitalWrite(IN2RolationLeft, HIGH);
   analogWrite(EnLeftMotor, speed);
}
void SpicialCase(int speed)
{
   RotateRight(speed);
   delay(2000);
   Forward(speed);
   delay(1000);
}
