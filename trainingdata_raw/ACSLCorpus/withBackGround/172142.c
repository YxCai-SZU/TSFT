#include <stdint.h>

/*@
    predicate valid_params(integer n, integer k) =
        n >= 1 && n <= 100000 &&
        k >= 1 && k <= n;

    logic integer compute_result(integer n, integer k) =
        n - k + 1;

    lemma result_bounds: \forall integer n, k;
        valid_params(n, k) ==> compute_result(n, k) >= 0 && compute_result(n, k) <= n - k + 1;
*/

/*@
    requires valid_params(n, k);
    ensures \result >= 0;
    ensures \result <= n - k + 1;
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t k)
{
    //@ assert n >= 1 && n <= 100000;
    //@ assert k >= 1 && k <= n;
    return n - k + 1;
}

int main(void)
{
    return 0;
}
