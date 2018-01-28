#include "stdafx.h"
#include "unittest-practice.h"
using namespace std;

int end() { cout << endl;  getchar(); return 0; }

double test(double x) {
	cout << x << endl;
	return x;
}

int main()
{
	test(100.1);
	return end();
}

