/*@
    predicate valid_params(integer d, integer t, integer s) =
        1 <= d && d <= 10000 &&
        1 <= t && t <= 10000 &&
        1 <= s && s <= 10000;

    lemma product_bound:
        \forall integer s, integer t;
        valid_params(1, t, s) ==> s * t <= 10000 * 10000;
*/

#include <stdbool.h>

/*@
    requires valid_params(d, t, s);
    ensures \result == (d <= s * t);
*/
bool func(int d, int t, int s)
{
    bool result;
    
    //@ assert valid_params(d, t, s);
    //@ assert s * t <= 10000 * 10000;
    
    result = d <= s * t;
    return result;
}
