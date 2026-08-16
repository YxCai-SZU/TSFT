#include <stddef.h>

/*@
    requires (1 <= (a) && (a) <= 3 &&
        1 <= (b) && (b) <= 3 &&
        (a) != (b));
    ensures \result == (6 - (a) - (b));
    ensures \result >= 1 && \result <= 3;
    ensures \result != a && \result != b;
*/
size_t func(size_t a, size_t b) {
    // Variable declarations at top of scope
    size_t res;
    
    //@ assert 6 - a - b >= 1;
    //@ assert 6 - a - b <= 3;
    //@ assert 6 - a - b != a;
    //@ assert 6 - a - b != b;
    
    res = 6 - a - b;
    return res;
}
