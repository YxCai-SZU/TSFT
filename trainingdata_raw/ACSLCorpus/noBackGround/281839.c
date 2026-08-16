#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000 &&
        1 <= (t) <= 10000 &&
        1 <= (s) <= 10000);
    ensures \result == true <==> d <= t * s;
    assigns \nothing;
*/
bool func(long d, long t, long s)
{
    long x;

    //@ assert t <= 10000;
    //@ assert s <= 10000;
    
    //@ assert t * s <= 10000 * 10000;
    
    x = t * s;
    
    //@ assert x == t * s;

    if (d > x) {
        return false;
    } else {
        //@ assert d <= t * s;
        return true;
    }
}
