#include <stdint.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= k <= n <= 100;

    lemma result_bounds:
        \forall integer n, k;
        valid_params(n, k) ==> 0 <= n - k + 1 <= n;
*/

/*@
    requires valid_params(n, k);
    ensures \result == n - k + 1;
    ensures 0 <= \result <= n;
*/
int64_t func(int64_t n, int64_t k)
{
    //@ assert valid_params(n, k);
    //@ assert 0 <= n - k + 1 <= n;
    return n - k + 1;
}
