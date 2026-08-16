#include <stddef.h>

/*@
    requires (0 <= (a) <= 23 && 0 <= (b) <= 23);
    ensures (0 <= (\result) < 24);
    assigns \nothing;
*/
size_t func(size_t a, size_t b)
{
    size_t c;
    size_t result;
    
    //@ assert (0 <= (a) <= 23 && 0 <= (b) <= 23);
    
    c = a + b;
    //@ assert 0 <= c <= 46;
    
    result = c % 24;
    
    //@ assert (0 <= (result) < 24);
    return result;
}
