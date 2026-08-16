#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 100 && 0 <= (p) && (p) <= 100);
    ensures \result >= 0 && \result <= a * 3 + p;
    ensures \result == (a * 3 + p) / 2;
*/
int32_t func(uint32_t a, uint32_t p)
{
    // Variable declarations at scope top
    uint32_t sum;
    uint32_t result;

    //@ assert (0 <= (a) && (a) <= 100 && 0 <= (p) && (p) <= 100);
    sum = a * 3 + p;
    //@ assert sum == ((a) * 3 + (p));
    result = sum / 2;
    //@ assert result == ((a) * 3 + (p)) / 2;
    //@ assert result >= 0 && result <= ((a) * 3 + (p));
    return (int32_t)result;
}
