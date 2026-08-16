#include <stddef.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
*/
size_t func(size_t r) {
    size_t pi;
    size_t result;

    pi = 3;
    
    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert 3 * r <= 300;
    //@ assert (3 * (r) * (r)) <= 300 * 100;
    
    result = pi * r * r;
    return result;
}
