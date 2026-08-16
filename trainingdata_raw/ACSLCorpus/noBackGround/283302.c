#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000 && 1 <= (t) <= 10000 && 1 <= (s) <= 10000);
    ensures \result == (s * t >= d);
    assigns \nothing;
*/
bool func(unsigned int d, unsigned int t, unsigned int s)
{
    long long distance;
    long long speed;
    long long time;
    long long product;
    bool result;

    distance = (long long)d;
    speed = (long long)s;
    time = (long long)t;

    //@ assert speed <= 10000;
    //@ assert time <= 10000;
    //@ assert distance <= 10000;

    product = speed * time;
    //@ assert product <= 10000LL * 10000LL;

    result = (distance <= product);
    return result;
}
