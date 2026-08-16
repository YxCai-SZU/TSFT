#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    lemma multiplication_bounds:
        \forall integer t, s;
            valid_range(t) && valid_range(s) ==> t * s <= 10000 * 10000;
*/

/*@
    requires valid_range(d);
    requires valid_range(t);
    requires valid_range(s);
    ensures \result == true <==> d <= t * s;
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations at scope top
    int product;
    bool result;

    //@ assert valid_range(t);
    //@ assert valid_range(s);
    //@ assert t * s <= 10000 * 10000;

    product = t * s;
    
    if (d <= product)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    
    return result;
}
