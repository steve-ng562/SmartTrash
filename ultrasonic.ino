#include <Servo.h>
#include <JeeLib.h> 

const int trigPin = 11;
const int echoPin = 12;
const int redPin = 6;
const int greenPin = 5;
const int bluePin = 3;
const int buttonPin = 2;
long duration;
int distance;
int pos = 0;

Servo myservo;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);

pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
Serial.begin(9600); // Starts the serial communication
}

void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
//delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration/29/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

if(distance < 15 && distance > 5){
myservo.write(110);
// yellow = 9, black = +, red = -
setColor(255,0,0);
delay(4000);

}
else
{
  myservo.write(150);
  setColor(0,255,0);
  delay(100);
 
}
  
  
}

void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
