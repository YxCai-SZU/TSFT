#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == (((a) + (b) + (c)) / 3);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t sum;
    uint32_t result;

    sum = a + b + c;
    result = sum / 3;

    //@ assert result == (((a) + (b) + (c)) / 3);
    return result;
}

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == (((a) + (b) + (c)) / 3);
    ensures 1 <= \result <= 100;
    assigns \nothing;
*/
uint32_t func_with_bounds(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t sum;
    uint32_t result;

    sum = a + b + c;
    result = sum / 3;

    //@ assert result == (((a) + (b) + (c)) / 3);
    //@ assert 1 <= result <= 100;
    return result;
}
