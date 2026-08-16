#include <stdint.h>

/*@
    requires ((a) <= 50 && (b) <= 50 && (a) + (b) <= 100);
    ensures \result == (((a) + (b) + 1) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t sum;
    uint32_t result;

    sum = a + b + 1;
    result = sum / 2;

    //@ assert result == (a + b + 1) / 2;

    return result;
}
