#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 10000;

    logic integer product(integer t, integer s) = t * s;

    lemma product_range:
        \forall integer t, s;
            valid_range(t) && valid_range(s) ==> 1 <= product(t, s) <= 10000 * 10000;
*/

/*@
    requires valid_range(d) && valid_range(t) && valid_range(s);
    ensures \result == (product(t, s) >= d);
*/
bool func(long d, long t, long s)
{
    // Variable declarations at top of scope
    long product;
    bool result;

    //@ assert valid_range(t);
    //@ assert valid_range(s);
    //@ assert 1 <= product(t, s) <= 10000 * 10000;

    product = t * s;
    //@ assert product == product(t, s);

    result = product >= d;
    //@ assert result == (product(t, s) >= d);

    return result;
}
