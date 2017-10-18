#include<iostream>
#include <vector>
#include<time.h>
#include"Perceptron.h"

using namespace std;

int activation(float a) { //sign(float)
	if (a < 0) return -1;
	else return 1;
}

Perceptron::Perceptron(int numWeights) { //constructor
										 //initialize weights with random vals[-1..1]

	for (int i = 0; i < numWeights; i++) {
		weights.push_back(((float)(rand()%200-100))/100);
		//cout << weights[i]<<endl;
	}
}

float Perceptron::guess(vector<float> inputs) {
	float sum = 0;
	for (int i = 0; i < this->weights.size(); i++) {
		sum += inputs[i] * weights[i];
	}
	return activation(sum);
}
