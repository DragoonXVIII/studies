
#ifndef TPUNKT_H
#define TPUNKT_H


class Tkolo;

class Tpunkt
{
    public:
        Tpunkt();
        Tpunkt(int x, int y): x(x), y(y){};
        ~Tpunkt();
        friend bool nalezy(Tpunkt *punkt, Tkolo *kolo);
        void ruch(int xMove, int yMove);
        int getX();
        int getY();

    private:
        int x;
        int y;
};

#endif // TPUNKT_H
