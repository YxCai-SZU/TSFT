#include <stddef.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result <= c;
    ensures \result == b / a || \result == c;
*/
size_t func(size_t a, size_t b, size_t c) {
    size_t result;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    result = b / a;
    
    if (result < c) {
        //@ assert result <= c;
        return result;
    } else {
        //@ assert c <= c;
        return c;
    }
}
