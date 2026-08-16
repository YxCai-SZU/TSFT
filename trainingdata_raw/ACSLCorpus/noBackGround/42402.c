#include <stddef.h>

/*@
    requires 1 <= x <= 100;
    ensures \result == x * x;
    assigns \nothing;
*/
size_t func(size_t x)
{
    //@ assert (1 <= (x) && (x) <= 100);
    
    //@ assert x * x <= 10000;
    
    return x * x;
}
