#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <string>
#include<fstream>
#include<sstream>

#include "Net.h"

void Net::getResults(vector<double> &resultVals) const {
	resultVals.clear();
	for (unsigned n = 0; n < m_layers.back().size() - 1; ++n) {
		resultVals.push_back(m_layers.back()[n].getOutputVal());
	}
}

Net::Net(const vector<unsigned> &topology) {
	unsigned numLayers = topology.size();

	for (unsigned layerNum = 0; layerNum < numLayers; layerNum++) {
		//new layer making
		m_layers.push_back(Layer());
		unsigned numOutputs = layerNum == topology.size() - 1 ? 0 : topology[layerNum + 1];

		//adding bias neuron to the layer
		for (unsigned neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum) {
			m_layers.back().push_back(Neuron(numOutputs, neuronNum));
			cout << "made " << neuronNum << " neuron of lyer:" << layerNum << endl;
		}

		//force bias neuron output 1.0
		m_layers.back().back().setOutputVal(1.0);
	}
}

void Net::feedForward(const vector<double> &inputVals) {

	//Assign input val to input neurons
	for (unsigned i = 0; i < inputVals.size(); i++) {
		m_layers[0][i].setOutputVal(inputVals[i]);
	}

	//forward propagate
	for (unsigned layerNum = 1; layerNum < m_layers.size(); ++layerNum) {
		Layer &prevLayer = m_layers[layerNum - 1];
		for (unsigned n = 0; n < m_layers[layerNum].size() - 1; ++n) {
			m_layers[layerNum][n].feedForward(prevLayer);
		}
	}
}

void Net::backProp(const vector<double> &targetVals) {
	//calculate overall net error (RMS /root mean square error/ of output neuron errors)
	Layer &outputLayer = m_layers.back();
	m_error = 0.0;

	for (unsigned n = 0; n < outputLayer.size() - 1; ++n) {
		double delta = targetVals[n] - outputLayer[n].getOutputVal();
		m_error += delta * delta;
	}
	m_error /= outputLayer.size() - 1; //average error squared
	m_error = sqrt(m_error); //RMS

							 //impement recent average measurement:
	m_recentAverageError =
		(m_recentAverageError * m_recentAverageSmoothingFactor + m_error)
		/ (m_recentAverageSmoothingFactor + 1.0);

	//calculate output layer gradients
	for (unsigned n = 0; n < outputLayer.size() - 1; ++n) {
		outputLayer[n].calcOutputGradients(targetVals[n]);
	}

	//calculate hidden layer gradients
	for (unsigned layerNum = m_layers.size() - 2; layerNum > 0; --layerNum) {
		Layer &hiddenLayer = m_layers[layerNum];
		Layer &nextLayer = m_layers[layerNum + 1];

		for (unsigned n = 0; n < hiddenLayer.size(); ++n) {
			hiddenLayer[n].calcHiddenGradients(nextLayer);
		}
	}

	//For all layers from outputs to first hidden layer update connection weights
	for (unsigned layerNum = m_layers.size() - 1; layerNum > 0; --layerNum) {
		Layer &layer = m_layers[layerNum];
		Layer &prevLayer = m_layers[layerNum - 1];

		for (unsigned n = 0; n < layer.size() - 1; ++n) {
			layer[n].updateInputWeights(prevLayer);
		}
	}

}