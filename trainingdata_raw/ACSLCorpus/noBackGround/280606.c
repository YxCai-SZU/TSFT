#include <stdint.h>

/*@
    requires (1 <= (a) <= 10) && (1 <= (b) <= 10);
    ensures \result == (((a) + (b) + 1) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t sum;
    uint32_t result;

    sum = a + b + 1;
    //@ assert sum == a + b + 1;
    result = sum / 2;
    //@ assert result == (((a) + (b) + 1) / 2);
    return result;
}
