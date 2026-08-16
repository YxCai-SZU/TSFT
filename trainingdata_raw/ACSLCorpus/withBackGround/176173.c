#include <limits.h>

/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;
    predicate product_in_range(integer x, integer y) = -1000000000000000000 <= x * y <= 1000000000000000000;
    logic integer abs_val(integer x) = x < 0 ? -x : x;
    lemma product_range_lemma:
        \forall integer a, b;
            in_range(a) && in_range(b) ==> product_in_range(a, b);
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    requires a <= b && c <= d;
    ensures \result == b * d || \result == b * c || \result == a * d || \result == a * c;
    assigns \nothing;
*/
long long func(long long a, long long b, long long c, long long d)
{
    long long max_val;
    long long temp_val;
    long long a_abs;
    long long b_abs;
    long long c_abs;
    long long d_abs;

    //@ assert product_in_range(a, c);
    max_val = a * c;

    //@ assert product_in_range(a, d);
    temp_val = a * d;
    //@ assert temp_val > max_val || temp_val <= max_val;
    if (temp_val > max_val)
    {
        max_val = temp_val;
    }

    //@ assert product_in_range(b, c);
    temp_val = b * c;
    //@ assert temp_val > max_val || temp_val <= max_val;
    if (temp_val > max_val)
    {
        max_val = temp_val;
    }

    //@ assert product_in_range(b, d);
    temp_val = b * d;
    //@ assert temp_val > max_val || temp_val <= max_val;
    if (temp_val > max_val)
    {
        max_val = temp_val;
    }

    a_abs = a < 0 ? -a : a;
    b_abs = b < 0 ? -b : b;
    c_abs = c < 0 ? -c : c;
    d_abs = d < 0 ? -d : d;

    //@ assert a_abs >= 0 && a_abs <= 1000000000;
    //@ assert b_abs >= 0 && b_abs <= 1000000000;
    //@ assert c_abs >= 0 && c_abs <= 1000000000;
    //@ assert d_abs >= 0 && d_abs <= 1000000000;

    return max_val;
}
