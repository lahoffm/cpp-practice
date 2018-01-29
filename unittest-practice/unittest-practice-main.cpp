#include "stdafx.h"
#include "unittest-practice.h"
using namespace std;

int end() { cout << endl;  getchar(); return 0; }

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

