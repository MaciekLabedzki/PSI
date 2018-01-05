public class Data {

    private double x[];
    private int inputCouter;
    private String y;

    public Data(int inputCouter) {
        this.inputCouter = inputCouter;
        this.x = new double[inputCouter];
    }

    public double getX(int i) {
        return x[i];
    }

    public void setX(int i,double x) {
        this.x[i] = x;
    }

    public int getInputCouter() {
        return inputCouter;
    }

    public void setInputCouter(int inputCouter) {
        this.inputCouter = inputCouter;
    }

    public String getY() {
        return y;
    }

    public void setY(String y) {
        this.y = y;
    }
}
