#include "stdafx.h"
#include "unittest-practice.h"
using namespace std;

int end(){ cout << endl;  getchar(); return 0; }

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
	return make_cstr("Temperature = ", " degrees C");
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

