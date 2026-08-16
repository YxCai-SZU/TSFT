#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000);
    ensures \result == ((((n) - 1) * (n)) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    // Variable declarations at top
    uint64_t ans;
    
    //@ assert n > 0 && n <= 1000000000;
    //@ assert n - 1 >= 0;
    //@ assert (n - 1) * n <= 1000000000000000000;
    
    ans = ((n - 1) * n) / 2;
    
    //@ assert ans == ((((n) - 1) * (n)) / 2);
    return ans;
}
