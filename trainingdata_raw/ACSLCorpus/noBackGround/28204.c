#include <stddef.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (a > 2 * b ? a - 2 * b : 0);
    assigns \nothing;
*/
size_t func(size_t a, size_t b) {
    size_t result;
    
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    
    if (a > 2 * b) {
        result = a - 2 * b;
        //@ assert result == a - 2 * b;
    } else {
        result = 0;
        //@ assert result == 0;
    }
    
    return result;
}
