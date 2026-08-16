#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n <= 1000000000;

    logic integer func_result(integer n) = (n - 1) * n / 2;

    lemma func_result_bound: \forall integer n; valid_n(n) ==> func_result(n) <= 9223372036854775807;
*/

/*@
    requires valid_n(n);
    ensures \result == func_result(n);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    // Variable declarations at scope top
    uint64_t result;

    if (n == 0)
    {
        result = 0;
    }
    else
    {
        //@ assert n > 0 && n <= 1000000000;
        //@ assert (n - 1) <= 1000000000;
        //@ assert (n - 1) * n <= 18446744073709551615ULL;
        //@ assert ((n - 1) * n) / 2 <= 9223372036854775807ULL;
        result = (n - 1) * n / 2;
    }

    return result;
}
