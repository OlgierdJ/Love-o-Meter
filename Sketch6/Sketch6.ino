/*
 Name:		Sketch6.ino
 Created:	7/28/2020 9:13:18 AM
 Author:	Janie
*/

const int sensorPin = A0;
const float baselineTemp = 20.0;

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	for (int i = 2; i < 5; i++)
	{
		pinMode(i, OUTPUT);
		digitalWrite(i, LOW);
	}
}

// the loop function runs over and over again until power down or reset
void loop() {
	int sensorVal = analogRead(sensorPin);
	Serial.print("Sensor Value: ");
	Serial.print(sensorVal);
	float voltage = (sensorVal/1024.0) * 5.0;
	Serial.print(", Volts: ");
	Serial.print(voltage);
	Serial.print(", degrees C: ");
	float temperature = (voltage - .5) * 100;
	Serial.print(temperature);
	Serial.print("\n");
	Serial.print("\n");
	Serial.print("\n");
	Serial.print("\n");
	Serial.print("\n");

	if (temperature<baselineTemp+2) {
		digitalWrite(2, LOW);
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
	}
	else if (temperature >= baselineTemp + 2 && temperature < baselineTemp + 4) {
		digitalWrite(2, HIGH);
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
	}
	else if (temperature >= baselineTemp + 4 && temperature < baselineTemp + 6) {
		digitalWrite(2, HIGH);
		digitalWrite(3, HIGH);
		digitalWrite(4, LOW);
	}
	else if (temperature >= baselineTemp + 6) {
		digitalWrite(2, HIGH);
		digitalWrite(3, HIGH);
		digitalWrite(4, HIGH);
	}
	delay(1);
}
