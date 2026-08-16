#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n <= 10000;

    logic integer compute_res(integer n) = ((n + 999) / 1000) * 1000 - n;

    lemma overflow_bound1: \forall integer n; valid_n(n) ==> n + 999 <= 10000 + 999;
    lemma overflow_bound2: \forall integer n; valid_n(n) ==> (n + 999) / 1000 <= 10;
    lemma overflow_bound3: \forall integer n; valid_n(n) ==> ((n + 999) / 1000) * 1000 <= 10000;
    lemma overflow_bound4: \forall integer n; valid_n(n) ==> ((n + 999) / 1000) * 1000 - n <= 10000 - 1;
*/

/*@
    requires 1 <= n <= 10000;
    ensures \result == ((n + 999) / 1000) * 1000 - n;
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    //@ assert n + 999 <= 10000 + 999;
    //@ assert (n + 999) / 1000 <= 10;
    //@ assert ((n + 999) / 1000) * 1000 <= 10000;
    //@ assert ((n + 999) / 1000) * 1000 - n <= 10000 - 1;

    uint32_t ans = ((n + 999) / 1000) * 1000 - n;
    return ans;
}
