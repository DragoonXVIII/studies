#include <iostream>

using namespace std;

int silnia(int n) {
    if(n == 0 || n == 1) return 1;
    return n * silnia(n-1);
}

void Hermite() {

    int w;
    cout<<"Liczba wezlow: "; cin>>w;
    double x[w], y[w];

    for(int i = 0; i < w; i++) {
        cout<<"Wartosc x["<<i<<"]: "; cin>>x[i];
    }
    for(int i = 0; i < w; i++) {
        cout<<"Wartosc y["<<i<<"]: "; cin>>y[i];
    }

    double tab[w];
    tab[0] = y[0];
    int j = 0, sumX = 1;
    for(int i = 1; i < w; i++) {
        if(x[i] == x[i-1]) {
            tab[i] = y[j+1];
            sumX++;
        } else {
            j += sumX;
            tab[i] = (y[j] - y[j - sumX]) / (x[i] - x[i-1]);
            sumX = 1;
        }
    }

    for(int i = 0; i < w; i++) {
        cout<<"tab["<<i<<"]: "<<tab[i]<<endl;
    }
    
}

int main(){
    
    Hermite();

    return 0;
}