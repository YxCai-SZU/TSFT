#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= k <= 10 && 1 <= n <= 100;

    logic integer compute_base(integer n, integer k) = n + k * 2;

    lemma result_cases:
        \forall integer n, integer k, integer result;
        valid_params(n, k) && result == (compute_base(n, k) < 1 ? 1 : compute_base(n, k)) ==>
        (result == compute_base(n, k) || result == 1);
*/

/*@
    requires valid_params(n, k);
    ensures \result == n + k * 2 || \result == 1;
    assigns \nothing;
*/
int func(int n, int k)
{
    int result;
    int base;

    //@ assert valid_params(n, k);
    base = n + k * 2;
    result = base;

    if (result < 1)
    {
        result = 1;
        //@ assert result == 1;
    }
    else
    {
        //@ assert result == n + k * 2;
    }

    //@ assert result == n + k * 2 || result == 1;
    return result;
}
