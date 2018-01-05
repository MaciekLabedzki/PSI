import java.util.ArrayList;
import java.util.Collections;

public class Network {
    double learningRate;
    int neuronCounter;
    int recordsCounter;
    int inputCounter;
    int limit;
    Data[] learningData;
    Data[] testingData;
    Layer layer;
    LoadData loadDataLearn;
    LoadData loadDataTest;
    public Network(double learningRate, int neuronCounter, int limit) {
        this.learningRate = learningRate;
        this.neuronCounter = neuronCounter;
        this.limit = limit;

        layer = new Layer(4,neuronCounter, learningRate);
        loadDataLearn = new  LoadData();
        loadDataTest = new  LoadData();
        learningData = loadDataLearn.loadData();
        testingData = loadDataTest.loadData();
    }

    public void learn(){
        normalise(learningData);
        normalise(testingData);

        int counter =0;
        ArrayList<Double> result;

        do {

            for (int i = 0; i < loadDataLearn.getRecordsCounter(); i++) {

                result = layer.calculateLayer(learningData[i]);
                layer.modify(result.indexOf( Collections.max( result )) );

                result.clear();
            }

            counter++;

        }while( counter < limit );

        System.out.println("Uczenie zakończone powodzeniem\nLiczba epok: " + counter + "\n\n");

    }

    public void testing(){
        ArrayList<Double> result;
        ArrayList<Integer> group = new ArrayList<Integer>();
        int winner;
        for(int i=0; i< loadDataTest.getRecordsCounter(); i++) {

            result = layer.calculateLayer(testingData[i]);


            winner = result.indexOf( Collections.max( result ));

            if(!group.contains(winner)){
                group.add(result.indexOf( Collections.max( result )));
            }



            System.out.println("ID: " + i + "  Rodzaj: " + testingData[i].getY() + "  WYNIK: " + winner );

        }

        System.out.println("\nLista zwycięskich grup: ");
        for(Integer el: group)
            System.out.println(el.toString());

    }

    public void normalise(Data[] data){
        for(int i =0 ; i< data.length; i++){
            double length = data[i].getX(0)*data[i].getX(0) +
                    data[i].getX(1)*data[i].getX(1) +
                    data[i].getX(2)*data[i].getX(2) +
                    data[i].getX(3)*data[i].getX(3);
            length = Math.sqrt(length);

            data[i].setX(0, data[i].getX(0)/length);
            data[i].setX(1, data[i].getX(1)/length );
            data[i].setX(2, data[i].getX(2)/length );
            data[i].setX(3, data[i].getX(3)/length );
        }
    }
}
