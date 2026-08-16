#include <stdint.h>

/*@
    requires (0 <= (a) <= 8 && 0 <= (b) <= 8);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
uint32_t test_fns(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t ans;

    //@ assert (0 <= (a) <= 8 && 0 <= (b) <= 8);
    //@ assert 0 <= ((a) * (b)) <= 64;

    ans = a * b;

    //@ assert ((a) * (b)) <= 100;
    //@ assert ((a) * (b)) <= 64;

    return ans;
}
