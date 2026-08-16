#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (a) <= (n) * (n));
    ensures \result == ((n) * (n) - (a));
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t a)
{
    //@ assert (1 <= (n) <= 100 && 0 <= (a) <= (n) * (n));
    
    //@ assert n * n <= 10000;
    //@ assert n * n >= 1;
    
    return n * n - a;
}
