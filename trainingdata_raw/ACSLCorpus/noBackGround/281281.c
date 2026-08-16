#include <stdint.h>

/*@
    requires (2 <= (n) && (n) <= 100);
    ensures \result == (((n) / 2) * (((n) + 1) / 2));
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    // Variable declarations at top of scope
    uint64_t ans;

    //@ assert n > 1 && n <= 100;
    //@ assert n / 2 >= 1 && n / 2 <= 50;
    //@ assert (n + 1) / 2 >= 1 && (n + 1) / 2 <= 50;
    //@ assert (n / 2) * ((n + 1) / 2) <= 2500;

    ans = (n / 2) * ((n + 1) / 2);
    return ans;
}
