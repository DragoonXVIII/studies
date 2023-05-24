
#ifndef TTIME_H
#define TTIME_H



#include <ostream>



class Ttime
{
public:
    Ttime();
    Ttime(int h = 0, int m = 0) : godziny(h), minuty(m) {};
    ~Ttime(){};

    Ttime operator+(const Ttime& other) const
    {
        int sum_godziny = godziny + other.godziny;
        int sum_minuty = minuty + other.minuty;

        if (sum_minuty >= 60)
        {
            sum_godziny += 1;
            sum_minuty -= 60;
        }

        return Ttime(sum_godziny, sum_minuty);
    }

    Ttime operator-(const Ttime& other) const
    {
        int diff_godziny = godziny - other.godziny;
        int diff_minuty = minuty - other.minuty;

        if (diff_minuty < 0)
        {
            diff_godziny -= 1;
            diff_minuty += 60;
        }

        return Ttime(diff_godziny, diff_minuty);
    }

    friend std::ostream& operator<<(std::ostream& os, const Ttime& time)
    {
        os << time.godziny << " godz. " << time.minuty << " min.";
        return os;
    }

    friend Ttime operator*(const Ttime& time, int multiplier)
    {
        int total_minuty = time.godziny * 60 + time.minuty;
        total_minuty *= multiplier;

        int result_godziny = total_minuty / 60;
        int result_minuty = total_minuty % 60;

        return Ttime(result_godziny, result_minuty);
    }

    friend bool operator==(const Ttime& lhs, const Ttime& rhs)
    {
        return (lhs.godziny == rhs.godziny) && (lhs.minuty == rhs.minuty);
    }

private:
    int godziny;
    int minuty;
};

#endif // TTIME_H
