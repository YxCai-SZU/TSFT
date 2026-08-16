#include <stdint.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= n <= 100000000000 &&
        1 <= k <= n;

    logic integer compute_result(integer n, integer k) =
        n - k + 1;

    lemma result_properties:
        \forall integer n, k;
        valid_params(n, k) ==>
            compute_result(n, k) >= 0 &&
            compute_result(n, k) <= n &&
            compute_result(n, k) == n - k + 1;
*/

/*@
    requires valid_params(n, k);
    ensures \result >= 0;
    ensures \result <= n;
    ensures \result == n - k + 1;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t k)
{
    int64_t answer;
    //@ assert valid_params(n, k);
    
    answer = n - k + 1;
    
    //@ assert answer >= 0;
    //@ assert answer <= n;
    //@ assert answer == n - k + 1;
    
    return answer;
}
