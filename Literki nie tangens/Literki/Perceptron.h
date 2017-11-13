#ifndef Perceptron_h
#define Perceptron_h

using namespace std;

class Perceptron {
public:
	double learningRate;
	vector<double> weights;

	Perceptron(int numWeights, double rate);
	double guess(vector<double> inputs);
	void train(vector<double> inputs, double target);
private:
};

#endif // !Perceptron_h

