#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;

    logic integer func_spec(integer n) = n * 800 - (n / 15) * 200;

    lemma n_times_800_bound: \forall integer n; valid_n(n) ==> n * 800 <= 100 * 800;
    lemma n_div_15_bound: \forall integer n; valid_n(n) ==> n / 15 <= 6;
    lemma div_times_200_bound: \forall integer n; valid_n(n) ==> (n / 15) * 200 <= 6 * 200;
*/

/*@
    requires valid_n(n);
    ensures \result == func_spec(n);
    assigns \nothing;
*/
int64_t func(uint64_t n)
{
    uint64_t x;
    uint64_t y;
    int64_t result;

    //@ assert n * 800 <= 100 * 800;
    x = n * 800;

    //@ assert n / 15 <= 6;
    //@ assert (n / 15) * 200 <= 6 * 200;
    y = (n / 15) * 200;

    result = (int64_t)(x - y);
    return result;
}
