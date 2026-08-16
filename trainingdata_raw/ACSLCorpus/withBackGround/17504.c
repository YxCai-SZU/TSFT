#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 1000000000;

    logic integer func_result(integer n) = n * (n - 1) / 2;

    lemma no_overflow_lemma:
        \forall integer n; valid_n(n) ==> n * (n - 1) <= 9223372036854775807 / 2;

    lemma div_no_overflow_lemma:
        \forall integer n; valid_n(n) ==> n * (n - 1) / 2 <= 9223372036854775807 / 2;
*/

/*@
    requires valid_n(n);
    ensures \result == func_result(n);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    // Variable declarations at top of scope
    uint64_t ans;

    //@ assert n > 0;
    //@ assert n <= 1000000000;
    //@ assert n * (n - 1) <= 9223372036854775807 / 2;
    //@ assert n * (n - 1) / 2 <= 9223372036854775807 / 2;

    ans = n * (n - 1) / 2;
    return ans;
}
