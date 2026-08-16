#include <stddef.h>

/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20) && (1 <= (t) <= 20);
    ensures \result == (t / a) * b;
    assigns \nothing;
*/
size_t func(size_t a, size_t b, size_t t)
{
    // Variable declarations at top of scope
    size_t result;

    //@ assert t / a <= 20;
    
    //@ assert (t / a) * b <= 400;
    
    result = (t / a) * b;
    return result;
}
