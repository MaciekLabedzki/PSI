
public class Main {
    public static void main(String args[]){

        Network network = new Network(0.95, 40, 30, 10000);
        network.learning();
        network.testing();

    }
}
