#include <stdbool.h>

/*@
    predicate in_range(integer x) = 1 <= x && x <= 100;

    logic integer mul_bounds(integer x, integer y) = x * y;
    lemma mul_in_range: \forall integer x, y; in_range(x) && in_range(y) ==> 1 <= mul_bounds(x, y) && mul_bounds(x, y) <= 10000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d) && in_range(e);
    ensures \result == ((a * b) <= c) || ((c * d) <= e) || (a * e <= b);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d, int e)
{
    int ab;
    int cd;
    int ae;
    int bc;
    int de;
    bool result;

    //@ assert in_range(a) && in_range(b);
    //@ assert 1 <= a * b && a * b <= 10000;
    //@ assert in_range(c) && in_range(d);
    //@ assert 1 <= c * d && c * d <= 10000;
    //@ assert in_range(a) && in_range(e);
    //@ assert 1 <= a * e && a * e <= 10000;
    //@ assert in_range(b) && in_range(c);
    //@ assert 1 <= b * c && b * c <= 10000;
    //@ assert in_range(d) && in_range(e);
    //@ assert 1 <= d * e && d * e <= 10000;

    ab = a * b;
    cd = c * d;
    ae = a * e;
    bc = b * c;
    de = d * e;

    result = (ab <= c) || (cd <= e) || (ae <= b);
    return result;
}
