#include <stdbool.h>

/*@
    requires (1 <= (d) && (d) <= 10000 &&
        1 <= (t) && (t) <= 10000 &&
        1 <= (s) && (s) <= 10000);
    ensures \result == (s * t >= d);
    assigns \nothing;
*/
bool func(unsigned int d, unsigned int t, unsigned int s)
{
    unsigned int distance = d;
    unsigned int speed = s;
    unsigned int time = t;

    //@ assert speed * time <= 10000 * 10000;

    return speed * time >= distance;
}
