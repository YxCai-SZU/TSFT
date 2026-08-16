#include <stdint.h>

/*@
    requires (1 <= (a) <= 1000000000 &&
        1 <= (b) <= 1000000000 &&
        1 <= (c) <= 1000000000);
    ensures \result <= c;
    ensures \result <= b / a;
    ensures \result == c || \result == b / a || \result == b / a - 1;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c)
{
    // Variable declarations at top of scope
    uint64_t result;
    
    //@ assert 1 <= a <= 1000000000;
    //@ assert 1 <= b <= 1000000000;
    //@ assert 1 <= c <= 1000000000;
    
    //@ assert b / a <= b;
    //@ assert c <= c;
    
    if (c < b / a) {
        result = c;
    } else {
        result = b / a;
    }
    
    //@ assert result <= c;
    //@ assert result <= b / a;
    //@ assert result == c || result == b / a || result == b / a - 1;
    
    return result;
}
