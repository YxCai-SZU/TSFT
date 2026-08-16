#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x && x <= 10000;
*/

/*@
    lemma multiplication_bounds: \forall integer t, integer s; 
        valid_range(t) && valid_range(s) ==> t * s <= 10000 * 10000;
*/

/*@
    requires valid_range(d) && valid_range(t) && valid_range(s);
    ensures \result == (t * s >= d);
    assigns \nothing;
*/
bool func(long d, long t, long s)
{
    long c;
    bool result;
    
    //@ assert valid_range(t);
    //@ assert valid_range(s);
    
    c = t * s;
    result = (c >= d);
    
    return result;
}
