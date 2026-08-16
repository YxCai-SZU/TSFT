#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result <= a + b * 2;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t max;
    uint32_t min;
    uint32_t ans;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    
    if (a > b * 2) {
        max = a;
    } else {
        max = b * 2;
    }
    
    //@ assert max == ((a) > (b) * 2 ? (a) : (b) * 2);
    
    if (a < b * 2) {
        min = a;
    } else {
        min = b * 2;
    }
    
    //@ assert min == ((a) < (b) * 2 ? (a) : (b) * 2);
    
    ans = max - min / 2;
    
    //@ assert ans == ((((a)) > ((b)) * 2 ? ((a)) : ((b)) * 2) - (((a)) < ((b)) * 2 ? ((a)) : ((b)) * 2) / 2);
    //@ assert ans <= a + b * 2;
    
    return ans;
}
