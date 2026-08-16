#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (a) <= (n) * (n));
    ensures \result == ((n) * (n) - (a));
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t a)
{
    int32_t nn;
    int32_t result;

    //@ assert n >= 1 && n <= 100;
    //@ assert n * n <= 10000;
    
    nn = n * n;
    
    //@ assert nn >= a && nn <= n * n;
    
    result = nn - a;
    return result;
}
