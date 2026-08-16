#include <stdint.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 200 && 1 <= m <= 200;

    logic integer product(integer n, integer m) = n * m;

    lemma product_bound:
        \forall integer n, m;
        valid_range(n, m) ==> product(n, m) <= 40000;
*/

/*@
    requires valid_range(n, m);
    ensures \result == product(n, m);
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t m)
{
    // Variable declarations at scope top
    uint32_t ans;

    //@ assert valid_range(n, m);
    //@ assert product(n, m) <= 40000;

    ans = n * m;

    //@ assert ans == product(n, m);

    return ans;
}
