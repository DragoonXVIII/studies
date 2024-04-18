#ifndef TOSOBAS_H
#define TOSOBAS_H



const int DL=20;



class TosobaS
{
    private:

        static int liczbaObiektow;//pole statyczne

    protected:

        char nazwisko[DL], imie[DL];
        int wiek;

    public:

        TosobaS();
        TosobaS(char *nazwisko, char *imie, int wiek);
        ~TosobaS();

        void podajDane();
        void wyswietl();

        static int ile();//metoda statyczna
};
#endif // TOSOBAS_H
