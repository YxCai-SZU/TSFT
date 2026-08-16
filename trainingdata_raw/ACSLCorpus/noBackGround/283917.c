#include <stddef.h>

/*@
    requires (0 <= (a) <= 23) && (0 <= (b) <= 23);
    ensures \result == ((a + b) % 24);
    assigns \nothing;
*/
size_t func(size_t a, size_t b) {
    // Variable declarations at scope top
    size_t result;

    //@ assert a + b <= 46;
    
    result = (a + b) % 24;
    return result;
}
