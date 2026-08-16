#include <stdint.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 1000000000 &&
        1 <= m <= 1000000000;

    lemma product_in_range:
        \forall integer n, m;
            valid_range(n, m) ==> 0 <= n * m <= 1000000000 * 1000000000;
*/

/*@
    requires valid_range(n, m);
    ensures \result == n * m;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t m)
{
    //@ assert valid_range(n, m);
    //@ assert n * m >= 0;
    //@ assert n * m <= 1000000000 * 1000000000;
    //@ assert n * m == n * m;
    return n * m;
}
