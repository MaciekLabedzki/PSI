import java.io.FileNotFoundException;

public class Main {
    public static void main(String[] args) {
        Network network = new Network(1,35,26);
        try {
            network.loadTrainData();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        network.showWeights();
        for (int i = 0; i < 500000; i++) {
            network.train();

        }
        network.showWeights();
        network.test();
    }
}
