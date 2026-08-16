#include <stdint.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= n <= 1000000000 &&
        1 <= k <= n;

    logic integer func_result(integer n, integer k) = n - k + 1;
*/

/*@
    requires valid_params(n, k);
    ensures \result == func_result(n, k);
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t k)
{
    uint64_t n_unsigned;
    uint64_t k_unsigned;
    uint64_t result_unsigned;
    int64_t result;

    // Declare all variables at the top
    n_unsigned = (n < 0) ? (uint64_t)(-n) : (uint64_t)n;
    k_unsigned = (k < 0) ? (uint64_t)(-k) : (uint64_t)k;

    //@ assert n_unsigned >= k_unsigned;
    //@ assert n_unsigned - k_unsigned <= 1000000000;

    result_unsigned = n_unsigned - k_unsigned + 1;
    result = (n < 0) ? -(int64_t)result_unsigned : (int64_t)result_unsigned;

    return result;
}
