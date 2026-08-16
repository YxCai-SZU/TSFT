#include <stdint.h>

/*@
    requires (0 <= (x) <= 10000) && (0 <= (y) <= 10000);
    ensures \result == (x * y) / 100;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    uint32_t product;
    uint32_t res;

    //@ assert (0 <= ((integer)x) <= 10000);
    product = x * y;
    //@ assert product <= 100000000;
    res = product / 100;
    return res;
}
