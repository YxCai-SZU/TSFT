#include <stddef.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100);
    ensures \result <= c;
    ensures \result <= b / a;
    ensures \result == c || \result == b / a;
    assigns \nothing;
*/
size_t func(size_t a, size_t b, size_t c)
{
    // Variable declarations at scope top
    size_t res;
    size_t result;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100 &&         1 <= (c) && (c) <= 100);
    
    res = b / a;
    
    //@ assert res == b / a;
    //@ assert res <= b / a;
    
    if (res < c) {
        result = res;
    } else {
        result = c;
    }
    
    //@ assert result <= c;
    //@ assert result <= b / a;
    //@ assert result == c || result == b / a;
    
    return result;
}
