#include <stdbool.h>

/*@
    predicate is_product_safe(integer t, integer s) =
        1 <= t <= 10000 && 1 <= s <= 10000 &&
        t * s <= 10000 * 10000;

    lemma product_safety:
        \forall integer t, s;
            1 <= t <= 10000 && 1 <= s <= 10000 ==>
            is_product_safe(t, s);
*/

/*@
    requires 1 <= d <= 10000;
    requires 1 <= t <= 10000;
    requires 1 <= s <= 10000;
    ensures \result == (t * s >= d);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    int ans;
    
    //@ assert is_product_safe(t, s);
    //@ assert t * s <= 10000 * 10000;
    
    ans = (t * s >= d);
    
    //@ assert ans == (t * s >= d);
    
    return ans;
}
