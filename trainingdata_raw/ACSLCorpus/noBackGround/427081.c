#include <stdint.h>
/*@
    requires (1 <= (a) && (a) <= 1000000000) && (1 <= (b) && (b) <= 1000000000) && (1 <= (c) && (c) <= 1000000000);
    ensures \result >= 0 && \result <= b / a;
    ensures \result <= c;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c)
{
    uint64_t result;
    //@ assert b / a <= b;
    //@ assert b / a >= 0;
    
    if (a > b) {
        result = 0;
        //@ assert result == 0;
    } else {
        result = b / a;
        //@ assert result == b / a;
    }
    
    if (result < c) {
        //@ assert result >= 0 && result <= b / a;
        //@ assert result <= c;
        return result;
    } else {
        //@ assert c >= 0 && c <= c;
        return c;
    }
}
