#include <stdint.h>

/*@ predicate is_within_range(integer x) = 1 <= x <= 10000; */

/*@
    requires is_within_range(a) && is_within_range(b) && is_within_range(c) && is_within_range(d);
    ensures \result >= 0;
    ensures \result <= a + b + c + d;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t min1;
    uint32_t min2;
    uint32_t min12;
    uint32_t max1;
    int32_t result;

    // Variable declarations at top
    min1 = (a < b) ? a : b;
    min2 = (c < d) ? c : d;
    min12 = (min1 < min2) ? min1 : min2;
    max1 = (a + b > c + d) ? a + b : c + d;

    if (min12 < max1)
    {
        //@ assert min12 < max1;
        result = (int32_t)(max1 - min12);
    }
    else
    {
        //@ assert min12 >= max1;
        result = 0;
    }

    return result;
}
