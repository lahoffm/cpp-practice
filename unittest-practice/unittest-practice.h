#pragma once
#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>

class Sensor {
public:
	double reading;
	std::string displayStr;
	Sensor(double);
	const char* make_cstr(std::string, std::string);
	virtual operator const char*();
};

class TemperatureSensor : public Sensor {
public:
	TemperatureSensor(double);
	operator const char*();
};

class PressureSensor : public Sensor {
public:
	PressureSensor(double);
	operator const char*();
};
