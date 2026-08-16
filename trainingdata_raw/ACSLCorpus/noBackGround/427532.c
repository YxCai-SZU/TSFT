#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000 &&
        1 <= (t) <= 10000 &&
        1 <= (s) <= 10000);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(long d, long t, long s)
{
    //@ assert (1 <= (d) <= 10000 &&         1 <= (t) <= 10000 &&         1 <= (s) <= 10000);
    
    //@ assert t * s <= 10000 * 10000;
    //@ assert d <= 10000 * 10000;
    //@ assert t * s >= 1;
    
    return d <= t * s;
}
