#include <stdint.h>

/*@
    requires ((l) > 0 && (b) > 0);
    requires ((uint64_t)(l) * (l) + (uint64_t)(b) * (b) <= 0xFFFFFFFF);
    ensures \result == l * l + b * b;
    assigns \nothing;
*/
uint32_t rectangle_diagonal_squared(uint32_t l, uint32_t b)
{
    //@ assert l > 0 && b > 0;
    uint32_t lsquared = l * l;
    //@ assert (uint64_t)l * l <= 0xFFFFFFFF;
    uint32_t bsquared = b * b;
    //@ assert (uint64_t)b * b <= 0xFFFFFFFF;
    uint32_t sum_of_squares = lsquared + bsquared;
    //@ assert (uint64_t)l * l + (uint64_t)b * b <= 0xFFFFFFFF;
    return sum_of_squares;
}
