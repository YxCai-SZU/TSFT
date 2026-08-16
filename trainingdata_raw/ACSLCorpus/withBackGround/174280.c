#include <stdint.h>

/*@
    predicate is_multiple_of_1000(integer x) = x % 1000 == 0;
 */

/*@
    requires 1 <= x <= 100000;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 <==> is_multiple_of_1000(x);
 */
uint32_t func(uint32_t x)
{
    uint32_t num;
    uint32_t rem;
    uint32_t is_multiple;

    num = 1000 * (x / 1000);
    rem = x % 1000;
    is_multiple = 0;

    if (rem == 0) {
        is_multiple = 1;
    }

    //@ assert is_multiple == 0 || is_multiple == 1;

    return is_multiple;
}
