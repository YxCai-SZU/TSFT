#include <stddef.h>

/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) * (1 + (a) + (a) * (a)));
    assigns \nothing;
*/
size_t func(size_t a) {
    // Variable declarations at scope top
    size_t result;
    
    //@ assert (1 <= (a) && (a) <= 10);
    
    //@ assert 1 + a + a * a <= 121;
    
    //@ assert a * (1 + a + a * a) <= 10 * 121;
    
    result = a * (1 + a + a * a);
    
    //@ assert result == ((a) * (1 + (a) + (a) * (a)));
    
    return result;
}
