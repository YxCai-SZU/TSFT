#include <stdint.h>
/*@
    requires (0 <= (x) && (x) <= 100);
    ensures \result == ((x) * (x) * (x));
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t ret;
    //@ assert 0 <= x && x <= 100;
    //@ assert x * x <= 10000;
    //@ assert x * x * x <= 1000000;
    ret = x * x * x;
    return ret;
}
