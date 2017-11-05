#include<iostream>
#include <vector>
#include<time.h>

#include"TrainingData.h"
#include"Net.h"
#include"Neuron.h"

using namespace std;

void showVectorVals(string label, vector<double> &v) {
	std::cout << label << " ";
	for (unsigned i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {
	srand(time(NULL));
	vector<unsigned> topology = { 35,4,1 };

	Net *net= new Net(topology);

	TrainingData data("TrainingData.txt");

	vector<double> labels;
	vector<vector<double>> results;
	vector<vector<double>> inputs;

	data.processData(&labels, &inputs);

	for (int i = 0; i < labels.size(); i++) {

		cout << endl << "Pass " << i+1;

		showVectorVals(": Inputs:", inputs[i]);
		net->feedForward(inputs[i]);

		results.push_back(*(new vector<double>));
		net->getResults(results[i]);
		showVectorVals("Outputs:", results[i]);
		
		vector<double> res = {};
		res.push_back(labels[i]);

		showVectorVals("Targets:", res);
		assert(results[i].size() == topology.back());
		net->backProp(res);

		cout << "Net recent average error: " << net->getRecentAverageError() << endl;
	}
	vector<double> Z = { 1,1,1,1,1, 0,0,0,0,1, 0,0,0,1,0, 0,0,1,0,0, 0,1,0,0,0, 1,0,0,0,0, 1,1,1,1,1, };
	vector<double> z = { 0,0,0,0,0, 0,0,0,0,0, 1,1,1,1,1, 0,0,0,1,0, 0,0,1,0,0, 0,1,0,0,0, 1,1,1,1,1, };

	vector<double> guess = {};
	net->feedForward(Z);
	net->getResults(guess);

	cout << "zgaduje Z: " << guess[0] << endl;

	net->feedForward(z);
	net->getResults(guess);

	cout << " zgaduje z:" << guess[0] << endl;

	system("pause");
	return 0;
}