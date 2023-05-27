
#ifndef TTIME_H
#define TTIME_H



#include <ostream>



class Ttime
{
    public:
        Ttime();
        Ttime(int h = 0, int m = 0) : godziny(h), minuty(m) {};
        ~Ttime(){};

        Ttime operator+( Ttime& other);


        Ttime operator-( Ttime& other);


        friend std::ostream& operator<<(std::ostream& os, Ttime& time)
        {
            os << time.godziny << " godz. " << time.minuty << " min.";
            return os;
        }

        friend Ttime operator*(Ttime& time, int multiplier);


        friend bool operator==(Ttime& time1, Ttime& time2)
        {
            return (time1.godziny == time2.godziny) && (time1.minuty == time2.minuty);
        }

    private:
        int godziny;
        int minuty;
};

#endif // TTIME_H
