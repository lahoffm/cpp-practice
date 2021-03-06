#include "stdafx.h"
#include "unittest-practice.h"
using namespace std;

// generic sensor
Sensor::Sensor(double myReading) : reading(myReading) {}
Sensor::operator const char*() {
	return make_cstr("Sensor reading = ", "");
}
const char* Sensor::make_cstr(string start, string end) {
	ostringstream display;
	display << start << reading << end << "\n";
	displayStr = display.str();
	return displayStr.c_str();
}

TemperatureSensor::TemperatureSensor(double tempReading) : Sensor(tempReading){}
TemperatureSensor::operator const char*() {
	return make_cstr("Temperature = ", " degrees K");
}

PressureSensor::PressureSensor(double pressureReading) : Sensor(pressureReading) {}
PressureSensor::operator const char*() {
	return make_cstr("Pressure = ", " pascals");
}

// uses PV=nRT ideal gas law
double getFreeSpace(TemperatureSensor& t_sensor, PressureSensor& p_sensor, double n, double R) {
	double T = t_sensor.reading;
	double P = p_sensor.reading;
	double V = (n*R*T)/P;
	return V;
}
