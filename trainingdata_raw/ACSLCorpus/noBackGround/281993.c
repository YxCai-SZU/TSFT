#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result >= 0;
    assigns \nothing;
*/
int32_t func(uint32_t n) {
    int32_t ans;
    
    //@ assert n / 2 + 1 >= 0;
    //@ assert n / 2 + 1 <= 51;
    
    if (n % 2 == 0) {
        ans = 1;
    } else {
        ans = 0;
    }
    
    //@ assert ans >= 0;
    return ans;
}
