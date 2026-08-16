#include <stdint.h>

/*@
    requires 1 <= x <= 20;
    requires 1 <= y <= 20;
    requires 1 <= z <= 20;
    ensures \result == x * (y + z);
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y, uint32_t z)
{
    // Variable declarations at scope top
    uint32_t ans;

    //@ assert (1 <= (x) <= 20);
    //@ assert (1 <= (y) <= 20);
    //@ assert (1 <= (z) <= 20);
    //@ assert ((y) + (z)) <= 40;
    //@ assert ((x) * (((y) + (z)))) <= 800;

    ans = x * (y + z);
    return ans;
}
