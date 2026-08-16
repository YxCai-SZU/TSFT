#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (a) <= (n) * (n));
    ensures \result == ((n) * (n) - (a));
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t a)
{
    // Variable declarations at top of scope
    int64_t nn;
    int64_t result;
    
    //@ assert n * n <= 100 * 100;
    
    nn = n * n;
    
    //@ assert nn >= 0 && nn <= 10000;
    //@ assert nn - a >= 0 && nn - a <= 10000;
    
    result = nn - a;
    return result;
}
