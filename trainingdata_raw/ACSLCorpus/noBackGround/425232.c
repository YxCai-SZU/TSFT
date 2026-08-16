#include <stdint.h>

/*@
    requires (0 <= (x) <= 100) && (0 <= (y) <= 100);
    ensures \result == ((x) * (y));
    assigns \nothing;
*/
uint32_t non_linear_arith_example(uint32_t x, uint32_t y)
{
    //@ assert ((x) * (y)) <= 10000;
    return x * y;
}
