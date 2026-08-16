/*@
    predicate valid_params(integer d, integer t, integer s) =
        1 <= d && d <= 10000 &&
        1 <= t && t <= 10000 &&
        1 <= s && s <= 10000 &&
        d <= t * s;

    lemma no_overflow: \forall integer d, integer t, integer s;
        valid_params(d, t, s) ==> t * s <= 100000000;
*/

#include <stdbool.h>

/*@
    requires valid_params(d, t, s);
    ensures \result == true;
*/
bool func(int d, int t, int s)
{
    //@ assert valid_params(d, t, s);
    
    //@ assert t * s <= 100000000;
    
    //@ assert d <= t * s;
    
    return d <= t * s;
}
