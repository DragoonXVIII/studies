
#include "ttime.h"

Ttime::Ttime()
{

}

Ttime Ttime::operator+(Ttime& other)
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


Ttime Ttime::operator-(Ttime& other)
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


Ttime operator*(Ttime& time, int multiplier)
{
    int total_minuty = time.godziny * 60 + time.minuty;
    total_minuty *= multiplier;

    int result_godziny = total_minuty / 60;
    int result_minuty = total_minuty % 60;

    return Ttime(result_godziny, result_minuty);
}
