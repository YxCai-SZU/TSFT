#include <stdint.h>

/*@
    logic integer compute_res(integer x) = (x / 500) * 1000 + ((x % 500) / 5) * 5;
 */

/*@
    requires 0 <= x <= 1000000000;
    ensures \result == compute_res(x);
    assigns \nothing;
 */
uint64_t func(uint64_t x)
{
    uint64_t n_500;
    uint64_t n_5;
    uint64_t res;

    n_500 = x / 500;
    n_5 = (x % 500) / 5;

    //@ assert n_500 == x / 500;
    //@ assert n_5 == (x % 500) / 5;

    res = n_500 * 1000 + n_5 * 5;
    return res;
}
