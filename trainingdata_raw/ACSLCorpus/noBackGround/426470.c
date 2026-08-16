#include <stddef.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (((a) + (b) + 1) / 2);
    assigns \nothing;
*/
size_t func(size_t a, size_t b) {
    size_t result;
    
    if ((a + b) % 2 == 0) {
        result = (a + b) / 2;
    } else {
        result = (a + b) / 2 + 1;
    }
    
    //@ assert result == (((a) + (b) + 1) / 2);
    
    return result;
}
