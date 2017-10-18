#ifndef Point_h
#define Point_h

using namespace std;

class Point {
public:
	float x, y;
	int label;

	Point();
	Point(float x, float y);
	void out();
};

#endif