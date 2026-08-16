#include <stddef.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result <= b + c;
    ensures \result >= b;
    assigns \nothing;
*/
size_t func(size_t a, size_t b, size_t c)
{
    size_t result;
    
    result = b;
    
    if (c > a)
    {
        result = result + (c - a);
    }
    
    //@ assert (c > a) ==> (result == b + c - a);
    //@ assert !(c > a) ==> (result == b);
    
    return result;
}
