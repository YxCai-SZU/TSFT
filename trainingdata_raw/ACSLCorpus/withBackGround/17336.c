#include <stdint.h>

/*@
    logic integer compute_res(integer n) =
        (n / 100) * 100 + ((n % 100) / 5) * 5;

    predicate valid_n(integer n) =
        1 <= n && n <= 10000;

    lemma n_100_bounds:
        \forall integer n; valid_n(n) ==> 0 <= n/100 && n/100 <= 100;

    lemma n_mod_100_div_5_bounds:
        \forall integer n; valid_n(n) ==> 0 <= (n % 100)/5 && (n % 100)/5 <= 20;
*/

/*@
    requires valid_n(n);
    ensures \result == compute_res(n);
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    uint32_t n_100;
    uint32_t n_mod_100;
    uint32_t n_mod_100_div_5;
    uint32_t ans;

    n_100 = n / 100;
    n_mod_100 = n % 100;
    n_mod_100_div_5 = n_mod_100 / 5;

    //@ assert n_100 <= 100;
    //@ assert n_mod_100_div_5 <= 20;

    ans = n_100 * 100 + n_mod_100_div_5 * 5;
    return ans;
}
