#include <stddef.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result <= a && \result <= b;
    ensures \result == a || \result == b;
    assigns \nothing;
*/
size_t func(size_t a, size_t b)
{
    size_t result;
    
    if (a > b)
    {
        //@ assert b <= a;
        //@ assert b <= b;
        //@ assert b == a || b == b;
        result = b;
    }
    else
    {
        //@ assert a <= a;
        //@ assert a <= b;
        //@ assert a == a || a == b;
        result = a;
    }
    
    return result;
}
