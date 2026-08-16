#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures ((\result) == (r) * (r));
    assigns \nothing;
*/
int32_t func(int32_t r) {
    int32_t result;
    
    result = r;
    
    if (r != 0) {
        //@ assert result == r;
        //@ assert 1 <= result <= 100;
        //@ assert 1 <= result * r <= 10000;
        result = result * r;
    }
    
    return result;
}
