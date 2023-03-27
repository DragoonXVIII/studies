#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string.h>



using namespace std;



class o_data
{
    public:

        int d,m,y;

        o_data();
        o_data(int d, int m, int y): d(d), m(m), y(y){};
        ~o_data();

        void load();
        void show();
        int getY();

    private:

    protected:

};

#endif // DATA_H
