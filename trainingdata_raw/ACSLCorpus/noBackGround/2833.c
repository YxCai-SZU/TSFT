#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * (n));
    assigns \nothing;
*/
size_t func(size_t n)
{
    //@ assert 1 <= n;
    //@ assert n <= 100;
    //@ assert n * n <= 10000;
    
    return n * n;
}
