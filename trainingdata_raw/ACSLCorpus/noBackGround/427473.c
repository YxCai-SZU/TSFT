#include <stdint.h>

/*@
    requires 1 <= n <= 20;
    requires 1 <= m <= 20;
    ensures (n < 10 && m < 10) ==> \result == n * m;
    ensures (n >= 10 || m >= 10) ==> \result == 0;
*/
uint32_t func(uint32_t n, uint32_t m) {
    uint32_t ans;
    
    if (n >= 10 || m >= 10) {
        ans = 0;
    } else {
        //@ assert (1 <= (n) <= 9);
        //@ assert (1 <= (m) <= 9);
        //@ assert n * m <= 81;
        ans = n * m;
    }
    
    return ans;
}
