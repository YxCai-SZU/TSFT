#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer product(integer s, integer t) = s * t;

    lemma product_range:
        \forall integer s, t;
            valid_range(s) && valid_range(t) ==> 1 <= product(s, t) <= 10000 * 10000;
*/

/*@
    requires valid_range(d);
    requires valid_range(t);
    requires valid_range(s);
    ensures \result == (s * t >= d);
*/
bool func(long d, long t, long s)
{
    long s_t_product;
    bool result;

    //@ assert valid_range(s);
    //@ assert valid_range(t);
    //@ assert 1 <= product(s, t) <= 10000 * 10000;

    s_t_product = s * t;

    //@ assert s_t_product == product(s, t);

    result = (s_t_product >= d);
    return result;
}
