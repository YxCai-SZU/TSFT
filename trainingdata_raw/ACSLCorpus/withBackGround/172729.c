#include <limits.h>

/*@
    predicate in_range(integer v) = -10000 <= v <= 10000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_in_range:
        \forall integer x, y;
            in_range(x) && in_range(y) ==> -1000000000 <= product(x, y) <= 1000000000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == product(a, c) || \result == product(a, d) || \result == product(b, c) || \result == product(b, d);
    ensures \result >= product(a, c) && \result >= product(a, d) && \result >= product(b, c) && \result >= product(b, d);
*/
long func(long a, long b, long c, long d)
{
    // Variable declarations at the top
    long max_value;
    long temp_value;

    //@ assert -1000000000 <= a * c <= 1000000000;
    max_value = a * c;

    //@ assert -1000000000 <= a * d <= 1000000000;
    temp_value = a * d;
    if (temp_value > max_value)
    {
        max_value = temp_value;
    }

    //@ assert -1000000000 <= b * c <= 1000000000;
    temp_value = b * c;
    if (temp_value > max_value)
    {
        max_value = temp_value;
    }

    //@ assert -1000000000 <= b * d <= 1000000000;
    temp_value = b * d;
    if (temp_value > max_value)
    {
        max_value = temp_value;
    }

    //@ assert max_value == a * c || max_value == a * d || max_value == b * c || max_value == b * d;
    return max_value;
}
