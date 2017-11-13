#include<iostream>
#include <vector>
#include<time.h>
#include"Point.h"

using namespace std;

Point::Point() {
	x = (double)(rand() % 200 - 100);
	y = (double)(rand() % 200 - 100);

	if (x > y) label = 1;
	else label = -1;
}

Point::Point(double x, double y) {
	this->x = x;
	this->y = y;

	if (x == 1 || y == 1) label = 1;
	else label = 0;
}

void Point::out() {
	cout << "Point (" << this->x << "," << this->y << ") - label: " << label << endl;
}
