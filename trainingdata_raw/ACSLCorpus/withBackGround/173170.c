#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bound:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> 
            product(x, y) <= 10000 * 10000;
*/

/*@
    requires valid_range(a) && valid_range(b);
    requires valid_range(c) && valid_range(d);
    ensures \result == product(a, b) || \result == product(c, d);
    ensures \result >= product(a, b);
    ensures \result >= product(c, d);
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long s1;
    long s2;
    long res;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);
    
    //@ assert product(a, b) <= 10000 * 10000;
    //@ assert product(c, d) <= 10000 * 10000;

    s1 = a * b;
    s2 = c * d;

    if (s1 > s2) {
        res = s1;
    } else {
        res = s2;
    }

    //@ assert res == product(a, b) || res == product(c, d);
    //@ assert res >= product(a, b);
    //@ assert res >= product(c, d);

    return res;
}
