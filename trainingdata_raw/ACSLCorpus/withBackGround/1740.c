#include <stdbool.h>

/*@
    predicate valid_params(integer d, integer t, integer s) =
        1 <= d <= 10000 && 1 <= t <= 10000 && 1 <= s <= 10000;
    
    logic integer product(integer t, integer s) = t * s;
    
    lemma product_bound: \forall integer t, s; 
        1 <= t <= 10000 && 1 <= s <= 10000 ==> product(t, s) <= 100000000;
*/

/*@
    requires valid_params(d, t, s);
    ensures \result == (t * s >= d);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    bool result;
    
    //@ assert 1 <= t <= 10000;
    //@ assert 1 <= s <= 10000;
    //@ assert t * s <= 100000000;
    
    result = (t * s >= d);
    return result;
}
