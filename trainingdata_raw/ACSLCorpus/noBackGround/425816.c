#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 23 &&
        0 <= (b) && (b) <= 23 &&
        (a) + (b) <= 23);
    ensures \result == ((a) + (b) < 24 ? (a) + (b) : (a) + (b) - 24);
    ensures \result >= 0 && \result <= 23;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t sum;
    uint32_t result;

    sum = a + b;

    //@ assert sum == a + b;

    if (sum < 24)
    {
        result = sum;
    }
    else
    {
        result = sum - 24;
    }

    //@ assert result == ((a) + (b) < 24 ? (a) + (b) : (a) + (b) - 24);
    //@ assert result >= 0 && result <= 23;

    return result;
}
