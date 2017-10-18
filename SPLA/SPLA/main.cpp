#include<iostream>
#include <vector>
#include<time.h>
#include"Perceptron.h"
#include"Point.h"


using namespace std;

int main() {
	srand(time(NULL));
	Perceptron *p = new Perceptron(2,(float)0.1);

	vector <Point> inputs;
	for (int i = 0; i < 100; i++) {
		cout << i + 1<<". ";
		inputs.push_back(*(new Point()));
		inputs.back().out();
	}
	cout << endl << endl;
	for (Point pt : inputs) {
		vector<float> inputs = { pt.x,pt.y };
		p->train(inputs, pt.label);
	}
	cout << "Training done" << endl<<endl;

	Point *test = new Point();
	vector<float> testInput = { test->x,test->y };
	if (p->guess(testInput) == test->label) cout << "Dziala!" << endl << endl;
	//////////////////////////////////////////////////////////////////

	Perceptron *or = new Perceptron(2, (float)0.1);
	vector<Point>orInputTeach = { Point(1,0), Point(0,1), Point(1,1) };
	
	Point orTest = Point(0,0) ;
	vector<float> orTestIntput = { orTest.x, orTest.y };
	
	for (Point pt : orInputTeach) { //trening OR
		vector<float> inputs = { pt.x,pt.y };
		or->train(inputs, pt.label);
	}
	if (p->guess(orTestIntput) == orTest.label) cout << "Or dziala!" << endl << endl;
	else cout << p->guess(orTestIntput) << endl;


	system("pause");
	return 0;
}