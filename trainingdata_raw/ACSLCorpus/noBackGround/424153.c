#include <stdint.h>

/*@
    requires 1 <= n <= 1000000000;
    ensures \result % 2 == 0;
    ensures \result >= 2;
    ensures \result == 2 * n || \result == n;
*/
uint32_t func(uint32_t n) {
    uint32_t ans;
    
    if (n % 2 == 0) {
        ans = n;
    } else {
        //@ assert 2 * n >= 2;
        ans = 2 * n;
    }
    
    //@ assert ans == 2 * n || ans == n;
    return ans;
}
