#include <stdint.h>

/*@
    requires ((a) <= 100 && (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at top of scope
    uint32_t ans;

    //@ assert a <= 100;
    //@ assert b <= 100;
    //@ assert ((a) * (b)) <= 10000;

    ans = a * b;
    return ans;
}
