import java.util.Random;

public class Neuron {

    public double[] in;
    public double[] w;
    public double lr;
    public double fr;
    public int size;


    public Neuron(double lr, double fr, int size) {
        this.in = new double[size];
        this.w = new double[size];
        this.lr = lr;
        this.fr = fr;
        this.size = size;

        init();
    }

    private void init() {
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            w[i] = random.nextDouble();
            in[i] = 0;
        }
    }

    double calc(){
        double tmp=0;
        for (int i = 0; i < size; i++) {
            tmp += in[i]* w[i];
        }
        return tmp;
    }

    double calculateSigmoid(double weightSum){
        return Math.signum(weightSum);
    }


}
