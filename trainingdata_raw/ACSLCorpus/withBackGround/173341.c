#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer max(integer x, integer y) = x > y ? x : y;

    lemma product_bound:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> x * y <= 10000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == a * b || \result == c * d;
    ensures \result >= a * b && \result >= c * d;
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long result;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);

    //@ assert a * b <= 10000;
    //@ assert c * d <= 10000;

    if (a * b > c * d)
    {
        result = a * b;
    }
    else
    {
        result = c * d;
    }

    //@ assert result == a * b || result == c * d;
    //@ assert result >= a * b && result >= c * d;

    return result;
}
