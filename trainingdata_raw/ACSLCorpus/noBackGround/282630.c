#include <stdint.h>

/*@
    requires (0 <= (a) <= 10);
    requires (0 <= (b) <= 10);
    requires (0 <= (c) <= 10);
    ensures \result == (((a) + (b)) * (c));
    assigns \nothing;
*/
uint32_t example(uint32_t a, uint32_t b, uint32_t c) {
    uint32_t result;
    
    //@ assert a + b <= 20;
    //@ assert (a + b) * c <= 200;
    
    result = (a + b) * c;
    
    //@ assert result == (((a) + (b)) * (c));
    return result;
}
