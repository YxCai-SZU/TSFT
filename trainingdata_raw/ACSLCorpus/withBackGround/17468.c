#include <stdint.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n && n <= 20 && 1 <= m && m <= 20;

    logic integer compute_result(integer n, integer m) =
        n * m - (n + m) + 1;

    lemma multiplication_bounds:
        \forall integer n, m;
            valid_range(n, m) ==> n * m >= 1 && n * m <= 400;

    lemma addition_bounds:
        \forall integer n, m;
            valid_range(n, m) ==> n + m >= 2 && n + m <= 40;
*/

/*@
    requires valid_range(N, M);
    ensures \result == compute_result(N, M);
    assigns \nothing;
*/
int32_t func(int32_t N, int32_t M)
{
    int32_t x;
    int32_t result;

    //@ assert N * M >= 1;
    //@ assert N * M <= 400;
    //@ assert N + M >= 2;
    //@ assert N + M <= 40;

    x = N * M;
    //@ assert x == N * M;
    
    x = x - (N + M) + 1;
    //@ assert x == compute_result(N, M);
    
    result = x;
    return result;
}
