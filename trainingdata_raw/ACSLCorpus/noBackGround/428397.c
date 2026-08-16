#include <stdint.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (d) <= 20);
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t d) {
    int32_t ans;
    int32_t steps;
    
    //@ assert (1 <= (n) <= 20 && 1 <= (d) <= 20);
    
    if (n <= d) {
        ans = 1;
    } else {
        ans = (n - d) / (d * 2) + 1;
    }
    
    if (n <= d) {
        steps = 1;
    } else {
        steps = (n - d) / (d * 2) + 1;
    }
    
    //@ assert steps == ((n) <= (d) ? 1 : ((n) - (d)) / ((d) * 2) + 1);
    //@ assert steps >= 0;
    //@ assert steps <= n;
    
    return steps;
}
