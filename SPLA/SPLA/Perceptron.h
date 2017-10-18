#ifndef Perceptron_h
#define Perceptron_h

using namespace std;

class Perceptron {
public:
	vector<float> weights;

	Perceptron(int numWeights);
	float guess(vector<float> inputs);
private:
};

#endif // !Perceptron_h

