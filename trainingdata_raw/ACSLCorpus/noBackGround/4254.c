#include <stddef.h>

/*@
    requires (0 <= (a) <= 23) && (0 <= (b) <= 23);
    requires ((a) % 1 == 0) && ((b) % 1 == 0);
    ensures (0 <= (\result) <= 23);
    ensures \result == (a + b) % 24;
*/
size_t func(size_t a, size_t b) {
    size_t result;
    
    //@ assert (a + b) % 24 <= 23;
    
    result = (a + b) % 24;
    return result;
}
