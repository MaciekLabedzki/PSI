#ifndef Perceptron_h
#define Perceptron_h

using namespace std;

class Perceptron {
public:
	float learningRate;
	vector<float> weights;

	Perceptron(int numWeights, float rate);
	float guess(vector<float> inputs);
	void train(vector<float> inputs, float target);
private:
};

#endif // !Perceptron_h

