#include <stdbool.h>

/*@ requires (1 <= (d) && (d) <= 10000 &&
      1 <= (t) && (t) <= 10000 &&
      1 <= (s) && (s) <= 10000);
    ensures \result == true <==> d <= s * t;
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    long distance;
    long speed;
    long time;
    long s_time;
    bool result;

    distance = (long)d;
    speed = (long)s;
    time = (long)t;

    //@ assert speed >= 1 && speed <= 10000;
    //@ assert time >= 1 && time <= 10000;
    //@ assert ((speed) * (time)) <= 100000000;

    //@ assert distance >= 1 && distance <= 10000;

    s_time = speed * time;
    //@ assert s_time == ((speed) * (time));

    result = (distance <= s_time);
    //@ assert result == true <==> distance <= s_time;

    return result;
}
