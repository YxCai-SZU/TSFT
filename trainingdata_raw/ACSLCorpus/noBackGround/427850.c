#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000000 &&
        1 <= (m) && (m) <= 1000000000000);
    ensures \result <= n + m / 2;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    uint64_t ans;
    
    //@ assert (1 <= (n) && (n) <= 1000000000000 &&         1 <= (m) && (m) <= 1000000000000);
    
    if (n > m / 2) {
        ans = m / 2;
        //@ assert ans <= n + m / 2;
    } else {
        ans = n + (m - 2 * n) / 4;
        //@ assert ans <= n + m / 2;
    }
    
    //@ assert ans <= n + m / 2;
    return ans;
}
