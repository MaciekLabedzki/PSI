//neural-net-tutorial.cpp
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <string>
#include<fstream>
#include<sstream>

#include "Net.h"
#include"TrainingData.h"

using namespace std;

void showVectorVals(string label, vector<double> &v) {
	std::cout << label << " ";
	for (unsigned i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {
	TrainingData trainData("trainingData.txt");

	vector<unsigned> topology;
	trainData.getTopology(topology);
	Net myNet(topology);

	vector<double> inputVals, targetVals, resultVals;
	int trainingPass = 0;

	while (!trainData.isEof()) {
		++trainingPass;
		cout << endl << "Pass " << trainingPass;

		//get new input data and feed it forward:
		if (trainData.getNextInputs(inputVals) != topology[0]) {
			break;
		}
		showVectorVals(": Inputs:", inputVals);
		myNet.feedForward(inputVals);

		//collect the nets actual result:
		myNet.getResults(resultVals);
		showVectorVals("Outputs:", resultVals);

		//train net what outputs should have been:
		trainData.getTargetOutputs(targetVals);
		showVectorVals("Targets:", targetVals);
		assert(targetVals.size() == topology.back());

		myNet.backProp(targetVals);
		
		//how the training is working
		cout << "Net recent average error: " << myNet.getRecentAverageError() << endl;
	}
	cout << endl << "Done" << endl;

	system("pause");
}