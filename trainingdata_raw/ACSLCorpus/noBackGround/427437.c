#include <stdbool.h>

/*@
    requires (1 <= (d) && (d) <= 10000) && (1 <= (t) && (t) <= 10000) && (1 <= (s) && (s) <= 10000);
    ensures \result == (t * s >= d);
    assigns \nothing;
*/
bool func(long d, long t, long s)
{
    // Variable declarations at scope top
    long product;
    bool result;
    
    //@ assert (1 <= (t) && (t) <= 10000) && (1 <= (s) && (s) <= 10000);
    //@ assert 1 <= t * s && t * s <= 10000 * 10000;
    
    product = t * s;
    result = (product >= d);
    
    return result;
}
