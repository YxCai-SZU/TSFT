#include <stdint.h>

/*@
    predicate valid_range(integer n) = 2 <= n <= 100;
    logic integer compute_result(integer n, integer m) = (n - 1) * (m - 1);
    lemma result_bounds: \forall integer n, m; valid_range(n) && valid_range(m) ==> 1 <= compute_result(n, m) <= 9801;
*/

/*@
    requires valid_range(N) && valid_range(M);
    ensures \result == compute_result(N, M);
    assigns \nothing;
*/
int32_t func(int32_t N, int32_t M)
{
    int32_t result;
    //@ assert N - 1 >= 1 && N - 1 <= 99;
    //@ assert M - 1 >= 1 && M - 1 <= 99;
    //@ assert (N - 1) * (M - 1) <= 99 * 99;
    result = (N - 1) * (M - 1);
    return result;
}
