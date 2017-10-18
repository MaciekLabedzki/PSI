#include<iostream>
#include <vector>
#include<time.h>
#include<math.h>
#include"Perceptron.h"

using namespace std;

//int activation(float a) { //sign(float)
//	if (a < 0) return 0;
//	else return 1;
//}

int activation(float a) { //hiperbolicznyTangens(float)
	return tanh(a);
}

Perceptron::Perceptron(int numWeights, float rate) { //constructor
										 //initialize weights with random vals[-1..1]
	learningRate=rate;
	for (int i = 0; i < numWeights+1; i++) {
		weights.push_back(((float)(rand()%200-100))/100);
		//cout << weights[i]<<endl;
	}
	
}

float Perceptron::guess(vector<float> inputs) {
	float sum = 0;
	for (int i = 0; i < this->weights.size()-1; i++) {
		sum += inputs[i] * weights[i];
	}
	sum += 1 * weights.back();//biasInput
	return activation(sum);
}

void Perceptron::train(vector<float> inputs, float target) {
	float guess = this->guess(inputs);
	float error = target - guess;

	for (int i = 0; i < this->weights.size()-1; i++) {
		weights[i] += error*inputs[i]*learningRate; 
	}
	weights.back() += error*learningRate;//biasInput
}