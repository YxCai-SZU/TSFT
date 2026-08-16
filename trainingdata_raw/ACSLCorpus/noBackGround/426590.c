#include <stdint.h>

/*@
    requires (1 <= (x) <= 32);
    requires (1 <= (y) <= 32);
    ensures \result == ((x) * (y));
    assigns \nothing;
*/
uint32_t test(uint32_t x, uint32_t y)
{
    // Variable declarations at scope top
    uint32_t ret;

    //@ assert (1 <= (x) <= 32);
    //@ assert (1 <= (y) <= 32);
    //@ assert ((x) * (y)) <= 1024;

    ret = x * y;
    return ret;
}
