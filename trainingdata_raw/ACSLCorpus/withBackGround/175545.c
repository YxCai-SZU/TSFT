#include <stdint.h>

/*@
    predicate valid_N(integer N) = 3 <= N && N <= 100;

    logic integer compute_result(integer N) = 180 * (N - 2);

    lemma result_bounds: \forall integer N; valid_N(N) ==> compute_result(N) <= 180 * (100 - 2);
*/

/*@
    requires valid_N(N);
    ensures \result == compute_result(N);
    assigns \nothing;
*/
int64_t func(int64_t N)
{
    // Variable declarations at scope top
    int64_t result;

    //@ assert N >= 3;
    //@ assert N <= 100;
    //@ assert 180 * (N - 2) <= 180 * (100 - 2);

    result = 180 * (N - 2);
    return result;
}
