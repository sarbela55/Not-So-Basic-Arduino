//Soren A.
//Hello Functions
//Use functions to code a LED to blink

#include <Servo.h>
#include <NewPing.h>
const int trigPin = 2;
const int echoPin = 3;
Servo myservo;
int pos = 0;
long duration, inches, cm;
int servoposition;

void setup()
{
	Serial.begin(9600);
	myservo.attach(5); //Says what pin the servo is attached to
}

void loop()
{
	
	pinMode(trigPin, OUTPUT);
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);         //2 microsecond delay
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);        //10 microsecond delay
	digitalWrite(trigPin, LOW);
	pinMode(echoPin, INPUT);
	duration = pulseIn(echoPin, HIGH, 10000);
	inches = microsecondsToInches(duration);
	cm = microsecondsToCentimeters(duration);
	Serial.print(inches);   //Gives the interval inches
	Serial.print("in, "); //Gives the interval "in,"
	Serial.print(cm);     //gives the interval cm
	Serial.print("cm");   //gives the interval "cm"
	Serial.println();     //Prints it in the serial monitor
	if (inches != 0)
	{
		if (inches <= 4)
		{
			sweep(3);
		}
		else
		{
			myservo.write(pos);
		}
		delay(100);     //Wait 100 milliseconds
	}
}

long microsecondsToInches(long microseconds)
{
	return microseconds / 74 / 2;    //gives the amount of microseconds back
}

long microsecondsToCentimeters(long microseconds)
{
	return microseconds / 29 / 2;     //gives the amount of microseconds back
}

void sweep(int NUM_OF_CYCLES)
{
	for (int j = 0; j < NUM_OF_CYCLES; j++)
		for (pos = 0; pos < 180; pos += 1)
		{
			myservo.write(pos);
			delay(2);     //wait 2 milliseconds
		}
	for (pos = 180; pos >= 1; pos -= 1)
	{
		myservo.write(pos);
		delay(2);    //Wait 2 milliseconds
	}
}
