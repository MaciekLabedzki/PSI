#include<iostream>
#include <vector>
#include<time.h>
#include"Perceptron.h"
#include"Point.h"
#include"TrainingData.h"

using namespace std;

int main() {
	srand(time(NULL));
	Perceptron *p = new Perceptron(35, (double)0.5);

	TrainingData data("TrainingData.txt");

	vector<double> labels;
	vector<vector<double>> inputs;

	data.processData(&labels, &inputs);

	for (int i = 0; i < labels.size(); i++) {
		p->train(inputs[i], labels[i]);
	}

	vector<double> Z = { 1,1,1,1,1, 0,0,0,0,1, 0,0,0,1,0, 0,0,1,0,0, 0,1,0,0,0, 1,0,0,0,0, 1,1,1,1,1, };
	vector<double> z = { 0,0,0,0,0, 0,0,0,0,0, 1,1,1,1,1, 0,0,0,1,0, 0,0,1,0,0, 0,1,0,0,0, 1,1,1,1,1, };

	cout << "zgaduje Z: " << p->guess(Z) << endl << " zgaduje z:" << p->guess(z) << endl;

	system("pause");
	return 0;
}