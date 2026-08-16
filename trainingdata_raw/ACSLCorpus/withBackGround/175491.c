#include <stdint.h>

/*@ predicate check_in_range(integer n, integer r) = n >= r; */
/*@ predicate check_decreasing(integer n, integer r) = n < r; */
/*@ predicate is_even(integer n) = n % 2 == 0; */

/*@
    requires 1 <= r <= 100;
    ensures \result == r * r;
    assigns \nothing;
*/
uint32_t func(uint32_t r)
{
    uint32_t res;
    //@ assert 1 <= r && r <= 100;
    //@ assert r * r <= 10000;
    res = r * r;
    return res;
}
