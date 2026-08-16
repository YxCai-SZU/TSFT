#include <limits.h>

/*@
    predicate in_range(integer v) =
        v >= -1000000000 && v <= 1000000000;

    logic integer product_in_range(integer x, integer y) =
        x * y;

    lemma product_bound:
        \forall integer x, y;
            in_range(x) && in_range(y) ==>
            product_in_range(x, y) >= -1000000000000000000 &&
            product_in_range(x, y) <= 1000000000000000000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == a * c || \result == a * d ||
            \result == b * c || \result == b * d ||
            \result == c * b;
    assigns \nothing;
*/
long long func(long long a, long long b, long long c, long long d)
{
    long long max1;
    long long max2;
    long long max3;
    long long max4;
    long long max5;
    long long max_value;

    //@ assert in_range(a);
    //@ assert in_range(c);
    //@ assert product_in_range(a, c) >= -1000000000000000000 && product_in_range(a, c) <= 1000000000000000000;
    max1 = a * c;

    //@ assert in_range(a);
    //@ assert in_range(d);
    //@ assert product_in_range(a, d) >= -1000000000000000000 && product_in_range(a, d) <= 1000000000000000000;
    max2 = a * d;

    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert product_in_range(b, c) >= -1000000000000000000 && product_in_range(b, c) <= 1000000000000000000;
    max3 = b * c;

    //@ assert in_range(b);
    //@ assert in_range(d);
    //@ assert product_in_range(b, d) >= -1000000000000000000 && product_in_range(b, d) <= 1000000000000000000;
    max4 = b * d;

    //@ assert in_range(c);
    //@ assert in_range(b);
    //@ assert product_in_range(c, b) >= -1000000000000000000 && product_in_range(c, b) <= 1000000000000000000;
    max5 = c * b;

    max_value = max1;

    if (max2 > max_value)
    {
        max_value = max2;
    }
    if (max3 > max_value)
    {
        max_value = max3;
    }
    if (max4 > max_value)
    {
        max_value = max4;
    }
    if (max5 > max_value)
    {
        max_value = max5;
    }

    return max_value;
}
