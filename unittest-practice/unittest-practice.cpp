#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int end(){ cout << endl;  getchar(); return 0; }

// generic sensor
class Sensor {
public:
	double reading;
	string displayStr;

	Sensor(double myReading) : reading(myReading) {}

	virtual operator const char*() {
		ostringstream display;
		display << "Sensor reading = " << reading << '\n';
		displayStr = display.str();
		return displayStr.c_str();
	}
};

class TemperatureSensor : public Sensor {
public:
	TemperatureSensor(double tempReading) : Sensor(tempReading){}

	operator const char*() {
		ostringstream display;
		display << "Temperature = " << reading << " degrees C\n";
		displayStr = display.str();
		return displayStr.c_str();
	}
};

class PressureSensor : public Sensor {
public:
	PressureSensor(double pressureReading) : Sensor(pressureReading) {}

	operator const char*() {
		ostringstream display;
		display << "Pressure = " << reading << " pascals\n";
		displayStr = display.str();
		return displayStr.c_str();
	}
};

// uses PV=nRT ideal gas law
double getFreeSpace(TemperatureSensor& t_sensor, PressureSensor& p_sensor, double n, double R) {
	double T = t_sensor.reading;
	double P = p_sensor.reading;
	double V = (n*R*T)/P;
	return V;
}

int main()
{
	double temperature = 10.1; // from some sensor input stream
	double pressure = 20.2; // from some sensor input stream
	double n = 0.8; // pre-calculated number of moles of gas
	double R = 8.31; // gas constant
	TemperatureSensor t_sensor(temperature);
	PressureSensor p_sensor(pressure);
	cout << t_sensor << p_sensor;

	double freeSpace = getFreeSpace(t_sensor, p_sensor, n, R);
	cout << "Free space volume = " << freeSpace << " m^3\n";
	
    return end();
}

