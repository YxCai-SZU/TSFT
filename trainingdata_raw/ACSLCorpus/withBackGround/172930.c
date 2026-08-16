#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= n <= 100 && 1 <= k <= 100;

    logic integer remainder(integer n, integer k) =
        n % k;

    lemma remainder_bounds:
        \forall integer n, k;
        valid_params(n, k) ==> 0 <= remainder(n, k) < k;
*/

/*@
    requires valid_params(n, k);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int func(unsigned int n, unsigned int k) {
    int r = (int)n;

    //@ assert 0 <= r <= n;
    //@ assert r < n + k;

    /*@
        loop invariant 0 <= r <= n;
        loop invariant r < n + k;
        loop invariant valid_params(n, k);
        loop assigns r;
        loop variant r;
    */
    while (r >= (int)k) {
        r -= (int)k;
    }

    //@ assert r < k;
    //@ assert r >= 0;

    if (r == 0) {
        return 0;
    } else {
        return 1;
    }
}
