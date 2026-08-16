#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000 &&
        1 <= (t) <= 10000 &&
        1 <= (s) <= 10000);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    int distance;
    int time;
    int speed;
    int distance_covered;
    bool result;

    distance = d;
    time = t;
    speed = s;

    //@ assert (1 <= (distance) <= 10000 &&         1 <= (time) <= 10000 &&         1 <= (speed) <= 10000);
    //@ assert 1 <= time <= 10000;
    //@ assert 1 <= speed <= 10000;
    //@ assert time * speed <= 100000000;

    distance_covered = time * speed;
    result = distance <= distance_covered;

    //@ assert result == (distance <= ((time) * (speed)));
    return result;
}
