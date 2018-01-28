#pragma once
#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Sensor {
public:
	double reading;
	string displayStr;
	Sensor(double myReading);
	const char* make_cstr(string start, string end);
	virtual operator const char*();
};

class TemperatureSensor : public Sensor {
public:
	TemperatureSensor(double tempReading);
	operator const char*();
};

class PressureSensor : public Sensor {
public:
	PressureSensor(double pressureReading);
	operator const char*();
};
