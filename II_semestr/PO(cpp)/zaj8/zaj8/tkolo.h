
#ifndef TKOLO_H
#define TKOLO_H


class Tpunkt;

class Tkolo
{
    public:
        Tkolo();
        Tkolo(int r): r(r){};
        ~Tkolo();
        int getR();
    private:
        int r;
};

#endif // TKOLO_H
