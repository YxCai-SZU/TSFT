#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000 && 1 <= (t) <= 10000 && 1 <= (s) <= 10000);
    ensures \result == true <==> (d <= t * s);
    assigns \nothing;
*/
bool func(long d, long t, long s)
{
    long distance;
    long time;
    long speed;
    long reach;
    bool result;

    distance = d;
    time = t;
    speed = s;

    //@ assert (1 <= (distance) <= 10000 && 1 <= (time) <= 10000 && 1 <= (speed) <= 10000);
    //@ assert 1 <= distance <= 10000;
    //@ assert 1 <= time <= 10000;
    //@ assert 1 <= speed <= 10000;
    //@ assert 1 <= ((time) * (speed)) <= 100000000;
    //@ assert ((time) * (speed)) == time * speed;

    reach = time * speed;

    //@ assert reach == ((time) * (speed));

    if (distance <= reach)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == true <==> (distance <= reach);
    return result;
}
