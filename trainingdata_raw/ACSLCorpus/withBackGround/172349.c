#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 10000;

    logic integer compute_res(integer n) = (1000 - n % 1000) % 1000;

    lemma res_bounds:
        \forall integer n; is_valid_n(n) ==> 0 <= compute_res(n) && compute_res(n) < 1000;
*/

/*@
    requires is_valid_n(n);
    ensures \result == compute_res(n);
    ensures \result < 1000;
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t res;

    //@ assert n >= 1 && n <= 10000;
    //@ assert 1000 - n % 1000 >= 0 && 1000 - n % 1000 <= 1000;
    //@ assert (1000 - n % 1000) % 1000 >= 0 && (1000 - n % 1000) % 1000 <= 1000;

    res = (1000 - n % 1000) % 1000;
    return res;
}
