#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 10000;
    
    lemma multiplication_bound:
        \forall integer t, s;
            valid_range(t) && valid_range(s) ==> t * s <= 10000 * 10000;
*/

/*@
    requires valid_range(d) && valid_range(t) && valid_range(s);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations at scope top
    int product;
    bool result;
    
    //@ assert t > 0 && s > 0;
    //@ assert t <= 10000 && s <= 10000;
    //@ assert t * s <= 10000 * 10000;
    
    product = t * s;
    result = d <= product;
    
    return result;
}
