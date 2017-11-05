#ifndef Point_h
#define Point_h

using namespace std;

class Point {
public:
	double x, y;
	int label;

	Point();
	Point(double x, double y);
	void out();
};

#endif