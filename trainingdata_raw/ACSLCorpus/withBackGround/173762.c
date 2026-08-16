#include <stdint.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= 100;

    lemma product_bound:
        \forall integer n, m;
            valid_range(n, m) ==> n * m <= 10000;
*/

/*@
    requires valid_range(n, m);
    ensures \result == (n * m) / 2;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    //@ assert valid_range(n, m);
    //@ assert n * m <= 10000;
    return (n * m) / 2;
}
