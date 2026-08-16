#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000);
    requires (1 <= (d) <= 10000);
    ensures \result == (b / c > d / a ? b / c : d / a);
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
    uint32_t result;
    uint32_t bc_div;
    uint32_t da_div;
    
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    
    bc_div = b / c;
    da_div = d / a;
    
    //@ assert bc_div <= b;
    //@ assert da_div <= d;
    
    if (bc_div > da_div) {
        result = bc_div;
    } else {
        result = da_div;
    }
    
    //@ assert result == (bc_div > da_div ? bc_div : da_div);
    return result;
}
