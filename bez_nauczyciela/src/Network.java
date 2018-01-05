import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Network {

    int ncnt;
    Neuron[] neurons;
    int inputSize;
    int inputCount;
    double[][] input;
    Scanner scanner;

    public Network(int ncnt, int inputSize, int inputCount) {
        this.ncnt = ncnt;
        this.inputSize = inputSize;
        this.inputCount = inputCount;
        this.neurons = new Neuron[ncnt];
        for (int i = 0; i < ncnt; i++) {
            neurons[i] = new Neuron(0.1,0.1,35);
        }
        this.input = new double[inputCount][inputSize];
        try {
            loadTrainData();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public void loadTrainData() throws FileNotFoundException {
        try {
             scanner = new Scanner(new File("a.txt"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        for (int i = 0; i < inputCount; i++) {
            for (int j = 0; j < inputSize; j++) {
                input[i][j] = scanner.nextDouble();
            }
        }
    }
    public void showInput(){
        for (int i = 0; i < inputCount; i++) {
            for (int j = 0; j < inputSize; j++) {
                System.out.println(input[i][j]);
            }
        }
    }
    public void showWeights(){
        for (int i = 0; i < ncnt; i++) {
            for (int j = 0; j < inputSize; j++) {
                System.out.println("Neuron "+i+" Weight "+j+ " = "+neurons[i].weights[j]);
            }
        }
    }

    public void train(){

        for (int letterNumber = 0; letterNumber < inputCount; letterNumber++) {


            for (int i = 0; i < ncnt; i++) {
                for (int j = 0; j < inputSize; j++) {
                    neurons[i].input[j] = input[letterNumber][j];
                }
            }
            double[] weightSum = new double[ncnt];
            for (int i = 0; i < ncnt; i++) {
                weightSum[i] = neurons[i].calculateWeightSum();
            }

            for (int i = 0; i < ncnt; i++) {
                for (int j = 0; j < inputSize; j++) {

                    neurons[i].weights[j] = neurons[i].weights[j]*neurons[i].forgetRate + neurons[i].learningRate*neurons[i].calculateSigmoid(weightSum[i])*(neurons[i].input[j] - neurons[i].weights[j]);

                }
            }
        }
    }

    public void test(){
        for (int letterNumber = 0; letterNumber <inputCount ; letterNumber++) {
            double[] result = new double[ncnt];

            for (int i = 0; i < ncnt; i++) {
                for (int j = 0; j < inputSize; j++) {
                    neurons[i].input[j] = input[letterNumber][j];
                }
            }
        }
    }

}
