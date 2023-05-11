
#ifndef TDOMOWNIK_H
#define TDOMOWNIK_H


#include <string>



using namespace std;



class Tdomownik
{
    public:
        Tdomownik();
        Tdomownik(string nazwa, string sekret, string kod): nazwa(nazwa), sekret(sekret){Tdomownik::kod = kod;};
        Tdomownik(string nazwa, string sekret): nazwa(nazwa), sekret(sekret){};
        ~Tdomownik();
        void show();
        void load();
        static void setkod();
        static void getkod();
        friend string sasiad(Tdomownik *domownik);
        friend class Tsasiad;

    private:
        string nazwa;
        string sekret;
        static string kod;

};

#endif // TDOMOWNIK_H
