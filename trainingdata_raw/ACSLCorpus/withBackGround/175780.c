#include <stdbool.h>

/*@
    predicate valid_params(integer d, integer t, integer s) =
        1 <= d <= 10000 &&
        1 <= t <= 10000 &&
        1 <= s <= 10000;
    
    logic integer product(integer t, integer s) = t * s;
    
    lemma product_bounds:
        \forall integer t, s;
        valid_params(10000, t, s) ==> product(t, s) <= 10000 * 10000;
*/

/*@
    requires valid_params(d, t, s);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(long d, long t, long s)
{
    // Variable declarations at scope top
    long x;
    bool result;
    
    //@ assert 1 <= t <= 10000;
    //@ assert 1 <= s <= 10000;
    //@ assert t * s <= 10000 * 10000;
    
    x = t * s;
    
    if (d <= x)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    
    //@ assert result == (d <= t * s);
    return result;
}
