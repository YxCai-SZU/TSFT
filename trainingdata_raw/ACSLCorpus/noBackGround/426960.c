#include <stddef.h>

/*@
    requires (0 <= (a) <= 23);
    requires (0 <= (b) <= 23);
    requires a != b;
    ensures (0 <= (\result) <= 23);
    ensures \result == ((a + b) % 24);
*/
size_t func(size_t a, size_t b) {
    // Variable declarations at top of scope
    size_t result;

    //@ assert 0 <= a + b <= 46;
    
    result = (a + b) % 24;
    return result;
}
