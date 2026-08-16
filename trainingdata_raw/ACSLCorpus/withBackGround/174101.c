#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer safe_product(integer t, integer s) = t * s;

    lemma product_bound: \forall integer t, s; 
        valid_range(t) && valid_range(s) ==> safe_product(t, s) <= 100000000;
*/

/*@
    requires valid_range(d) && valid_range(t) && valid_range(s);
    ensures \result == true <==> d <= t * s;
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert valid_range(t);
    //@ assert valid_range(s);
    //@ assert safe_product(t, s) <= 100000000;

    if (d <= t * s) {
        result = true;
    } else {
        //@ assert d > t * s;
        result = false;
    }

    return result;
}
