#include <stdint.h>

/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 100 &&
        0 <= m <= n * (n - 1) / 2;

    logic integer total_pairs(integer n) = n * (n - 1) / 2;

    lemma total_pairs_bound: \forall integer n; 1 <= n <= 100 ==> total_pairs(n) <= 4950;
*/

/*@
    requires valid_params(n, m);
    ensures \result == total_pairs(n) - m;
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t m)
{
    // Variable declarations at scope top
    uint32_t total_pairs;
    uint32_t res;

    //@ assert 1 <= n <= 100;
    //@ assert 0 <= m <= total_pairs(n);
    //@ assert total_pairs(n) <= 4950;

    total_pairs = n * (n - 1) / 2;
    res = total_pairs - m;

    //@ assert res == total_pairs(n) - m;
    return res;
}
