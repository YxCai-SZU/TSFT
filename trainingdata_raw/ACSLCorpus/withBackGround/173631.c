#include <limits.h>

/*@
    predicate in_range(integer v) = -1000 <= v <= 1000;
    predicate product_in_range(integer x, integer y) = -1000000 <= x * y <= 1000000;
*/

/*@
    lemma product_range_lemma:
        \forall integer a, integer d;
            in_range(a) && in_range(d) ==> product_in_range(a, d);
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == a * c || \result == a * d || \result == b * c || \result == b * d;
    ensures \result >= a * c && \result >= a * d && \result >= b * c && \result >= b * d;
*/
long func(long a, long b, long c, long d)
{
    long max_value;
    long current_value;

    //@ assert product_in_range(a, c);
    max_value = a * c;

    //@ assert product_in_range(a, d);
    current_value = a * d;

    if (current_value > max_value)
    {
        max_value = current_value;
    }

    //@ assert product_in_range(b, c);
    current_value = b * c;

    if (current_value > max_value)
    {
        max_value = current_value;
    }

    //@ assert product_in_range(b, d);
    current_value = b * d;

    if (current_value > max_value)
    {
        max_value = current_value;
    }

    //@ assert max_value >= a * c;
    //@ assert max_value >= a * d;
    //@ assert max_value >= b * c;
    //@ assert max_value >= b * d;

    return max_value;
}
