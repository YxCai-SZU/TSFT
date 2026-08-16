#include <stdbool.h>

/*@
  requires (1 <= (d) <= 10000) && (1 <= (t) <= 10000) && (1 <= (s) <= 10000);
  ensures \result == (t * s >= d);
  assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations at scope top
    int speed_distance;
    bool result;

    //@ assert t > 0 && t <= 10000;
    //@ assert s > 0 && s <= 10000;
    //@ assert 1 <= t && t <= 10000 && 1 <= s && s <= 10000;
    //@ assert t * s <= 10000 * 10000;

    speed_distance = t * s;
    
    if (speed_distance < d) {
        result = false;
    } else {
        result = true;
    }
    
    return result;
}
