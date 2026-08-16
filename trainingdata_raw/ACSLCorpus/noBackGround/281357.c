#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000);
    requires (1 <= (t) <= 10000);
    requires (1 <= (s) <= 10000);
    ensures \result == (s * t >= d);
*/
bool func(int d, int t, int s)
{
    int distance;
    int time;
    int speed;
    bool result;

    distance = d;
    time = t;
    speed = s;

    //@ assert (1 <= (speed) <= 10000);
    //@ assert (1 <= (time) <= 10000);
    //@ assert speed * time >= 1;
    //@ assert speed * time <= 10000 * 10000;

    result = speed * time >= distance;
    return result;
}
