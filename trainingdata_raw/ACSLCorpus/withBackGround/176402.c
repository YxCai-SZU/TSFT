#include <stdint.h>

/*@ predicate is_even(integer x) = x % 2 == 0; */

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == ((a + b) % 2 == 0 ? (a + b) / 2 : (a + b) / 2 + 1);
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t sum;
    uint32_t half;
    uint32_t result;

    sum = a + b;
    half = sum / 2;

    if (sum % 2 == 0)
    {
        result = half;
        //@ assert result == half;
    }
    else
    {
        result = half + 1;
        //@ assert result == half + 1;
    }

    return result;
}
