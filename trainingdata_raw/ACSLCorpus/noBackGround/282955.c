#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result <= c;
    ensures \result == ((b) / (a)) || \result == c;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c) {
    uint32_t result;
    
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    //@ assert ((b) / (a)) <= 100;
    //@ assert c <= 100;
    
    result = b / a;
    
    if (result > c) {
        //@ assert result == ((b) / (a));
        //@ assert result > c;
        return c;
    } else {
        //@ assert result == ((b) / (a));
        //@ assert result <= c;
        return result;
    }
}
