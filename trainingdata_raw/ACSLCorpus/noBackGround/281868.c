#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == ((a) + (b) < 10 ? 0 : (a) + (b) - 10);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b) {
    uint32_t sum;
    int32_t result;
    
    sum = a + b;
    
    if (sum < 10) {
        result = 0;
    } else {
        //@ assert sum >= 10;
        //@ assert sum - 10 <= 190;
        result = (int32_t)(sum - 10);
    }
    
    return result;
}
