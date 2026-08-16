#include <stdbool.h>

/*@
  requires (1 <= (d) <= 10000 &&
      1 <= (t) <= 10000 &&
      1 <= (s) <= 10000);
  ensures \result == true <==> d <= s * t;
  assigns \nothing;
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

    //@ assert speed <= 10000;
    //@ assert time <= 10000;
    //@ assert speed * time <= 100000000;

    if (distance <= speed * time)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
