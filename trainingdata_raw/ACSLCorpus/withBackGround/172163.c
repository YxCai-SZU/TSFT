#include <stdint.h>

/*@
    predicate non_overflow(uint32_t n) =
        n <= 100 &&
        (uint64_t)n * (uint64_t)(n + 1) / 2 <= UINT32_MAX;

    logic integer sum_formula(integer n) =
        n * (n + 1) / 2;
*/

/*@
    requires n <= 100;
    requires non_overflow(n);
    ensures \result == sum_formula(n);
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    //@ assert sum_formula(n) >= 0;
    return n * (n + 1) / 2;
}
