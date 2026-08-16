#include <stdbool.h>

/*@
    predicate within_bounds(integer d, integer t, integer s) =
        1 <= d <= 10000 && 1 <= t <= 10000 && 1 <= s <= 10000;

    predicate product_in_range(integer t, integer s) =
        t * s <= 10000 * 10000;

    lemma product_bound:
        \forall integer t, s;
            1 <= t <= 10000 && 1 <= s <= 10000 ==> product_in_range(t, s);
*/

/*@
    requires within_bounds(d, t, s);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations at scope top
    bool result;

    //@ assert within_bounds(d, t, s);
    
    // Check if the product t * s does not cause overflow
    //@ assert t <= 10000 && s <= 10000;
    
    if (t == 10000 || s == 10000) {
        //@ assert 1 <= d <= 10000;
        result = (d <= t * s);
        return result;
    }
    
    // Main condition check
    //@ assert 1 <= d <= 10000;
    //@ assert product_in_range(t, s);
    
    result = (d <= t * s);
    return result;
}
