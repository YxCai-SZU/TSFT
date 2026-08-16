#include <stddef.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    ensures \result <= a;
    ensures \result == 0 || a >= b;
    assigns \nothing;
*/
size_t func(size_t a, size_t b)
{
    size_t result;
    
    if (a >= b)
    {
        result = a - b;
    }
    else
    {
        //@ assert a < b;
        result = 0;
    }
    
    return result;
}
