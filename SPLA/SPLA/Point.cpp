#include<iostream>
#include <vector>
#include<time.h>
#include"Point.h"

using namespace std;

Point::Point(){
	x = (float)(rand() % 200 - 100);
	y = (float)(rand() % 200 - 100);

	if (x > y) label = 1;
	else label = -1;
}

Point::Point(float x, float y) {
	this->x = x;
	this->y = y;

	if (x==1 || y==1) label = 1;
	else label = 0;
}

void Point::out() {
	cout << "Point (" << this->x << "," << this->y << ") - label: " << label << endl;
}
