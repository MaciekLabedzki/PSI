import java.util.ArrayList;

public class Layer {

    private Neuron[] neuron;
    private int ictr;
    private int nctr;
    private double lr;
    private Data data;

    public Layer(int ictr, int nctr, double lr) {
        this.inputCounter = ictr;
        this.neuronCounter = nctr;
        this.learningRate = learningRate;

        neuron = new Neuron[nctr];
        for (int i = 0; i < nctr; i++) {
            neuron[i]=new Neuron(lr,ictr);
        }
    }

    public ArrayList<Double> calculateLayer(Data input){
        ArrayList<Double> results = new ArrayList<Double>();
        this.data = input;

        for (int i=0 ; i < neuron.length; i++){
            results.add(neuron[i].calculate(input));
        }

        return results;
    }

    public void modify(int id){
        neuron[id].modify(data);
    }

}
