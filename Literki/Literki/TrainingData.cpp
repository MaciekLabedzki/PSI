#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <string>
#include<fstream>
#include<sstream>

#include"TrainingData.h"


TrainingData::TrainingData(const string filename) {
	m_trainingDataFile.open(filename.c_str());
}

void TrainingData::processData(vector<double> *labels, vector<vector<double>> *inputs) {
	while (!isEof()) {
		string line;
		getline(m_trainingDataFile, line);
		stringstream ss(line);
		double oneValue;
		ss >> oneValue;
		labels->push_back(oneValue);//czy ok

		getline(m_trainingDataFile, line);
		stringstream dd(line);
		vector<double> tmp;
		while (dd >> oneValue) {
			tmp.push_back(oneValue);
		}
		inputs->push_back(tmp);
	}
	
}