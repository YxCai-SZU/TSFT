#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result == a * b;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b)
{
    // Variable declarations at top of scope
    uint64_t ans;

    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert a * b <= 100 * 100;

    ans = a * b;
    return ans;
}
