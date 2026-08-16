#include <stdbool.h>

/*@
    requires (1 <= (d) && (d) <= 10000 &&
        1 <= (t) && (t) <= 10000 &&
        1 <= (s) && (s) <= 10000);
    ensures \result == true <==> d <= t * s;
    assigns \nothing;
*/
bool func(long d, long t, long s)
{
    long distance;
    long time;
    long speed;
    long traveled;
    bool result;

    distance = d;
    time = t;
    speed = s;

    //@ assert (1 <= (distance) && (distance) <= 10000 &&         1 <= (time) && (time) <= 10000 &&         1 <= (speed) && (speed) <= 10000);
    //@ assert ((time) * (speed)) <= 10000 * 10000;

    traveled = time * speed;

    if (traveled >= distance)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == true <==> distance <= ((time) * (speed));
    return result;
}
