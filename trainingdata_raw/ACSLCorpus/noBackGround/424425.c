#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000 &&
        1 <= (t) <= 10000 &&
        1 <= (s) <= 10000);
    ensures \result == (t * s >= d);
    assigns \nothing;
*/
bool func(long d, long t, long s)
{
    // Variable declarations at scope top
    bool result;
    long product;

    //@ assert t > 0 && s > 0;
    //@ assert t <= 10000 && s <= 10000;
    
    product = t * s;
    //@ assert 1 <= product <= 10000 * 10000;
    
    result = (product >= d);
    return result;
}
