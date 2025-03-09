package pl.jm.lab2;

public class ModelOceny {

    private int ocena;

    public ModelOceny() {
        this.ocena = 0;
    }

    public ModelOceny(int ocena) {
        this.ocena = ocena;
    }

    public ModelOceny(String nazwa, int ocena) {
        this.ocena = ocena;
    }

    public int getOcena() {
        return ocena;
    }

    public void setOcena(int ocena) {
        this.ocena = ocena;
    }
}

