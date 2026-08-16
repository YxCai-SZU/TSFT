#include <stdint.h>

/*@
    predicate valid_range(integer n) = 1 <= n <= 100;

    logic integer double_triple(integer n) = n * 2 * 3;

    lemma arithmetic_lemma:
        \forall integer n, integer pi;
            valid_range(n) && pi == 3 ==> n * 2 * pi == double_triple(n);
*/

/*@
    requires valid_range(N);
    ensures \result == double_triple(N);
    assigns \nothing;
*/
int64_t func(int64_t N)
{
    int64_t pi;
    int64_t result;

    pi = 3;
    //@ assert pi == 3;
    //@ assert N * 2 * pi == N * 2 * 3;
    result = N * 2 * pi;
    return result;
}
