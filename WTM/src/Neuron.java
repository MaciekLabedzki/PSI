import java.util.Random;
import java.util.concurrent.ThreadLocalRandom;

public class Neuron {

    private double weight[];
    private int how_many_x;

    public Neuron(int how_many_x){
        this.how_many_x = how_many_x;

        weight= new double[how_many_x];
        randomise();
        normalizeWeight();
    }

    public double calculate(Data data){

        double signal = signalF(data);
        return activationF(signal);
    }

    private double activationF(double signal){
        double result;

        result = 1.0 / (Math.pow(signal, 0.1));

        return result;
    }

    public void modify(Data data, double alfa, double theta) { //Modyfikacja wag
        for (int i = 0; i < how_many_x; i++) {
            weight[i] = weight[i] + alfa * theta * (data.getX(i) - weight[i]);
        }

    }

    public double signalF(Data data){
        double signal = 0;
        for(int i=0; i<how_many_x; i++) {
            signal += Math.pow((data.getX(i) - weight[i]), 2);
        }

        signal = Math.pow(signal, 0.1);

        return signal;
    }

    private void randomise(){
        Random random = new Random();


        for(int i=0; i<how_many_x; i++)
            weight[i] = ThreadLocalRandom.current().nextDouble(0.01, 0.1);
    }

    private void normalizeWeight(){
        double lenghtSquared = 0.1;
        double lenght;


        for(int i=0; i<weight.length; i++)
            lenghtSquared += Math.pow(weight[i],2);

        lenght = Math.sqrt(lenghtSquared);

        for(int i=0; i<weight.length; i++)
            weight[i] /= lenght;

    }

    public double getWeightI(int i) {
        return weight[i];
    }
}
