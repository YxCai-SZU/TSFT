#include <stdbool.h>

/*@
    predicate valid_params(integer x, integer y, integer m, integer n) =
        1 <= m && m <= x && x <= 10000 &&
        1 <= n && n <= y && y <= 10000;

    logic integer mul_bound(integer a, integer b) = a * b;

    lemma mul_bounds:
        \forall integer x, y, m, n;
        valid_params(x, y, m, n) ==>
        mul_bound(m, y) <= 10000 * 10000 &&
        mul_bound(x, n) <= 10000 * 10000;
*/

/*@
    requires valid_params(x, y, m, n);
    ensures \result == (m * y <= x * n);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y, unsigned int m, unsigned int n)
{
    //@ assert valid_params(x, y, m, n);
    //@ assert m * y <= 10000 * 10000;
    //@ assert x * n <= 10000 * 10000;
    return m * y <= x * n;
}
