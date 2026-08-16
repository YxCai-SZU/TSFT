#include <stdint.h>

/*@
    requires 0 <= a <= b <= 1000000000000000000;
    requires 1 <= x <= 1000000000000000000;
    ensures \result <= b / x - a / x + 1;
    ensures \result >= b / x - a / x;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t x) {
    uint64_t ans;
    
    //@ assert (0 <= (a) <= (b) <= 1000000000000000000);
    //@ assert (1 <= (x) <= 1000000000000000000);
    //@ assert ((a) / (x) <= (b) / (x));
    
    if (a % x == 0) {
        ans = b / x - a / x + 1;
    } else {
        ans = b / x - a / x;
    }
    
    return ans;
}
