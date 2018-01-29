#include "pch.h"
#include "../unittest-practice.h"
#include "../unittest-practice.cpp"
#include <iostream>
using namespace std;

int end() { cout << endl;  getchar(); return 0; }

TEST(FreeSpaceTest, VolumeAboveZero) {
	// Test designed to fail with nonsensical data (negative temperature)
	double temperature = -10;
	double pressure = 20.0;
	double n = 1.0; // pre-calculated number of moles of gas
	double R = 8.31; // gas constant
	TemperatureSensor t_sensor(temperature);
	PressureSensor p_sensor(pressure);
	double freeSpace = getFreeSpace(t_sensor, p_sensor, n, R);
	ASSERT_TRUE(freeSpace >= 0.00);
}


TEST(FreeSpaceTest, VolumeMatchesFormula) {
	// Test if result matches PV=nRT formula
	double temperature = 3.14;
	double pressure = 1.59;
	double n = 2.8; // pre-calculated number of moles of gas
	double R = 8.31; // gas constant
	TemperatureSensor t_sensor(temperature);
	PressureSensor p_sensor(pressure);
	double freeSpace = getFreeSpace(t_sensor, p_sensor, n, R);
	double epsilon = 0.001;
	double trueFreeSpace = (n*R*temperature) / pressure;
	ASSERT_TRUE(std::abs(freeSpace - trueFreeSpace) < epsilon);
}

GTEST_API_ int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return end();
}
