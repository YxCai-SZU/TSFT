#include <stdbool.h>

/*@ requires (1 <= (d) && (d) <= 10000 &&
      1 <= (t) && (t) <= 10000 &&
      1 <= (s) && (s) <= 10000);
    ensures \result == (s * t >= d);
    assigns \nothing;
*/
bool func(unsigned int d, unsigned int t, unsigned int s)
{
    unsigned int distance;
    unsigned int time;
    unsigned int speed;
    bool result;

    distance = d;
    time = t;
    speed = s;

    //@ assert speed <= 10000;
    //@ assert time <= 10000;
    //@ assert speed * time <= 10000 * 10000;

    result = (speed * time >= distance);
    return result;
}
