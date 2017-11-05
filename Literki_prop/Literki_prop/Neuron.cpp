#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <string>
#include<fstream>
#include<sstream>

#include"Neuron.h"

double Neuron::eta = 0.1; //overall net learning rate[0..1]
double Neuron::alpha = 0.1; //momentum - multiplier of last deltaWeight [0..n]


void Neuron::updateInputWeights(Layer &prevLayer) {
	//weights to update are in connection container (in neurons in precerding layer)
	for (unsigned n = 0; n < prevLayer.size(); ++n) {
		Neuron &neuron = prevLayer[n];
		double oldDeltaWeight = neuron.m_outputWeights[m_myIndex].deltaWeight;

		double newDeltaWeight =
			//individual input, magnified by the gradient and train rate:
			eta
			* neuron.getOutputVal()
			* m_gradient
			//add momentum = fraction of the prev delta weight
			+ alpha
			*oldDeltaWeight;

		neuron.m_outputWeights[m_myIndex].deltaWeight = newDeltaWeight;
		neuron.m_outputWeights[m_myIndex].weight += newDeltaWeight;

	}
}

double Neuron::sumDOW(const Layer &nextLayer) const {
	double sum = 0.0;

	//sum our contributions of the errors at the node we feed
	for (unsigned n = 0; n < nextLayer.size() - 1; ++n) {
		sum += m_outputWeights[n].weight * nextLayer[n].m_gradient;
	}

	return sum;
}

void Neuron::calcHiddenGradients(const Layer &nextLayer) {
	double dow = sumDOW(nextLayer);
	m_gradient = dow*Neuron::transferFunctionDerivative(m_outputVal);
}

void Neuron::calcOutputGradients(double targetVal) {
	double delta = targetVal - m_outputVal;
	m_gradient = delta *Neuron::transferFunctionDerivative(m_outputVal);
}

double Neuron::transferFunction(double x) {
	//tanh - output range [-1..1]
	return tanh(x);
}

double Neuron::transferFunctionDerivative(double x) {
	//tanh derivative
	return 1.0 - x * x;
}

Neuron::Neuron(unsigned numOutputs, unsigned myIndex) {
	for (unsigned c = 0; c < numOutputs; c++) {
		m_outputWeights.push_back(Connection());
		m_outputWeights.back().weight = randomWeight();
	}

	m_myIndex = myIndex;
}

void Neuron::feedForward(const Layer &prevLayer) {
	//sum - prev layers outputs (our inputs) (include the bias node)
	double sum = 0.0;

	for (unsigned n = 0; n < prevLayer.size(); ++n) {
		sum += prevLayer[n].getOutputVal() *
			prevLayer[n].m_outputWeights[m_myIndex].weight;
	}

	m_outputVal = Neuron::transferFunction(sum);
}