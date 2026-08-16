#include <stdbool.h>

/*@ requires 1 <= d <= 10000;
    requires 1 <= t <= 10000;
    requires 1 <= s <= 10000;
    ensures \result == (t * s >= d);
*/
bool func(int d, int t, int s)
{
    int x;
    
    //@ assert (1 <= (t) <= 10000 && 1 <= (s) <= 10000);
    //@ assert t * s <= 10000 * 10000;
    
    x = t * s;
    //@ assert x == t * s;
    
    if (x < d) {
        //@ assert x < d;
        return false;
    } else {
        //@ assert x >= d;
        return true;
    }
}
