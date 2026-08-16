#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000) && (1 <= (t) <= 10000) && (1 <= (s) <= 10000);
    ensures \result == (s * t >= d);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    int distance = d;
    int speed = s;
    int time = t;

    //@ assert (1 <= (speed) <= 10000);
    //@ assert (1 <= (time) <= 10000);
    //@ assert speed * time <= 100000000;

    return speed * time >= distance;
}
