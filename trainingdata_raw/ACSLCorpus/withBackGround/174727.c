#include <stdint.h>

/*@
    predicate valid_params(integer n, integer k) =
        0 <= n <= 1000000000000000000 &&
        1 <= k <= 1000000000000000000;

    predicate loop_invariant(integer res, integer n, integer k) =
        0 <= res <= n &&
        1 <= k <= 1000000000000000000;
*/

/*@
    requires valid_params(n, k);
    ensures \result >= 0;
    ensures \result < k;
    ensures \result <= n;
*/
int64_t func(int64_t n, int64_t k)
{
    int64_t res = n;

    /*@
        loop invariant loop_invariant(res, n, k);
        loop assigns res;
        loop variant res;
    */
    while (res >= k)
    {
        //@ assert res >= k;
        res -= k;
        //@ assert res >= 0;
    }

    //@ assert res >= 0;
    //@ assert res < k;
    //@ assert res <= n;
    return res;
}
