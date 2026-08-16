#include <stddef.h>

/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20) && (1 <= (t) <= 20);
    ensures \result == b * (t / a);
    assigns \nothing;
*/
size_t func(size_t a, size_t b, size_t t)
{
    //@ assert (1 <= (a) <= 20);
    //@ assert (1 <= (b) <= 20);
    //@ assert (1 <= (t) <= 20);
    //@ assert t / a <= 20;
    //@ assert b * (t / a) <= 400;
    
    return b * (t / a);
}
