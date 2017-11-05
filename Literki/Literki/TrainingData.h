#ifndef TrainingData_h
#define TrainingData_h

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <string>
#include<fstream>
#include<sstream>

using namespace std;

//class to read data from file
class TrainingData {
public:
	TrainingData(const string filename);
	bool isEof(void) { return m_trainingDataFile.eof(); }

	void processData(vector<double> *labels, vector<vector<double>> *inputs);

private:
	ifstream m_trainingDataFile;
	
};

#endif
