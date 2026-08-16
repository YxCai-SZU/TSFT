#include <stdint.h>

/*@
    requires (0 <= (a) <= 100) && (0 <= (b) <= 100) && (0 <= (c) <= 100);
    ensures \result <= a + b + c;
    ensures \result >= ((c <= a + b) ? (a + b - c) : 0);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c) {
    uint32_t min;
    uint32_t result;
    
    //@ assert (0 <= (a) <= 100);
    //@ assert (0 <= (b) <= 100);
    //@ assert (0 <= (c) <= 100);
    
    if (c < a + b) {
        min = c;
    } else {
        min = a + b;
    }
    
    //@ assert min == (((c) < (a) + (b)) ? (c) : ((a) + (b)));
    //@ assert min <= a + b + c;
    
    result = a + b - min;
    
    //@ assert result <= a + b + c;
    //@ assert result >= ((c <= a + b) ? (a + b - c) : 0);
    
    return result;
}
