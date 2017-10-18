#include<iostream>
#include <vector>
#include<time.h>
#include"Perceptron.h"
#include"Point.h"


using namespace std;

int main() {
	srand(time(NULL));
	Perceptron *p = new Perceptron(10);
	vector<float> inputs = { (float)1.0,  (float)-1.0,  
							 (float)0.1,  (float)0.0, 
							 (float) 1.0, (float) 0.5,  
							 (float)-0.1,  (float)1.0, 
							 (float)-1.0,  (float)0.1, 
							 (float)0.0,  (float)1.0, 
							 (float)0.5, (float)-0.1 };
	//cout<<p->guess(inputs)<<endl;

	vector <Point> a;
	for (int i = 0; i < 100; i++) {
		cout << i + 1<<". ";
		a.push_back(*(new Point()));
		a.back().out();
	}

	system("pause");
	return 0;
}