import java.util.Random;
import java.util.concurrent.ThreadLocalRandom;

public class Neuron {

    private double learningRate;
    private double weight[];
    private int inputCounter;

    private void normaliseWeights() {
        double lengthSquared = weight[0]*weight[0] + weight[1]*weight[1] + weight[2]*weight[2] + weight[3]*weight[3];
        double length = Math.sqrt(lengthSquared);

        weight[0] /= length;
        weight[1] /= length;
        weight[2] /= length;
        weight[3] /= length;
    }

    private void randomiseWeights() {
        for (int i = 0; i < inputCounter; i++) {
            weight[i] = ThreadLocalRandom.current().nextDouble(0.01, 0.1);
        }
    }

    public Neuron(double learningRate, int inputCounter) {
        this.learningRate = learningRate;
        this.inputCounter = inputCounter;

        weight = new double[inputCounter];
        randomiseWeights();
        normaliseWeights();
    }

    public double calculate(Data input) {
        double signal = signalF(input);
        return signal;
    }

    private double signalF(Data data){
        double signal = 0;
        for(int i=0; i<inputCounter; i++) {
            signal += data.getX(i) * weight[i];
        }

        return signal;
    }

    public void modify(Data data) {
        for (int i = 0; i < inputCounter; i++) {
            weight[i] = weight[i] + learningRate * (data.getX(i) - weight[i]);
        }

        normaliseWeights();
    }
}
