#include <iostream>

using namespace std;

int silnia(int n) {
    if(n == 0 || n == 1) return 1;
    return n * silnia(n-1);
}

void Hermite() {

    int w, sumaK = 0;
    double pkt;
    cout<<"Liczba roznych wezlow: "; cin>>w;
    double tabX[w];
    int k[w];
     
    for(int i = 0; i < w; i++) {
        cout<<"Wartosc x["<<i<<"]: "; cin>>tabX[i];
    }
    for(int i = 0; i < w; i++) {
        cout<<"Krotnosc x["<<i<<"]: "; cin>>k[i];
        sumaK += k[i];
    }
    
    double tabY[w][sumaK];

    for(int i = 0; i < w; i++) {
        for(int j = 0; j < k[i]; j++) {
            cout<<"Wartosc y";
            for(int z = 0; z < j; z++) { cout<<"\'"; }
            cout<<"["<<i<<"]: "; cin>>tabY[i][j];
        }
    }

    cout<<"Punkt: "; cin>>pkt;

    double x[sumaK], y[sumaK];

    int z = 0;
    for(int i = 0; i < sumaK; i++) {
        x[i] = tabX[z];
        y[i] = tabY[z][0];
        k[z] -= 1;
        if(k[z] == 0) {
            z++;
        }
    }

    for(int i = 0; i < sumaK; i++) {
        cout<<"x["<<i<<"]: "<<x[i]<<"\t";
        cout<<"y["<<i<<"]: "<<y[i]<<endl;
    }

    for(int i = 1; i < sumaK; i++) {
        for(int j = sumaK-1; j >= i; j--) {
            if(x[j] == x[j-i]) {
                for(int z = 0; z < w; z++) {
                    if(x[j] == tabX[z]) {
                        y[j] = tabY[z][i] / silnia(i);
                    }
                }
            } else {
                y[j] = (y[j] - y[j-1]) / (x[j] - x[j-i]);
            }
        }
        for(int l = i; l < sumaK; l++) {
        cout<<"tab["<<l<<"] = "<<y[l]<<endl;
        } cout<<endl;
    }

    double wynik = 0, v;

    for(int i = 0; i < sumaK; i++) {
        v = 1;
        for(int j = 0; j < i; j++) {
            v *= pkt-x[j];
        }
        wynik += y[i] * v;
    }
    cout<<endl<<"Wynik: "<<wynik<<endl;
}

int main(){
    
    Hermite();

    return 0;
}