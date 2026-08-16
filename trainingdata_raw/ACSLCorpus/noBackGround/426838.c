#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000) && (1 <= (t) <= 10000) && (1 <= (s) <= 10000);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    long distance;
    long speed;
    long time;
    long covers;
    bool result;
    
    distance = (long)d;
    speed = (long)s;
    time = (long)t;
    
    //@ assert time * speed <= 10000 * 10000;
    
    covers = time * speed;
    result = distance <= covers;
    
    return result;
}
