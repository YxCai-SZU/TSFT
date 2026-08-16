#include <stdint.h>

/*@
    requires (1 <= (n) <= 1000000000);
    ensures \result == ((n) / 2 + (n) % 2);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    // Variable declarations at top of scope
    uint64_t ans;

    //@ assert n / 2 <= 500000000;
    //@ assert n % 2 <= 1;
    //@ assert n / 2 + n % 2 <= 500000001;

    ans = n / 2 + n % 2;
    return ans;
}
