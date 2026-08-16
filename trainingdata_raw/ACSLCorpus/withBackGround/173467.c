#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= k && k <= n && n <= 50;

    logic integer func_result(integer n, integer k) =
        n - k + 1;

    lemma func_result_bounds:
        \forall integer n, k;
        valid_params(n, k) ==> 1 <= func_result(n, k) <= 50;
*/

/*@
    requires valid_params(n, k);
    ensures \result == func_result(n, k);
    assigns \nothing;
*/
int func(int n, int k)
{
    //@ assert valid_params(n, k);
    //@ assert 1 <= n - k + 1;
    //@ assert n - k + 1 <= 50;
    return n - k + 1;
}
