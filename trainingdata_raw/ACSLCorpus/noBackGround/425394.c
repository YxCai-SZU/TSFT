#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (a) <= (n) * (n));
    ensures \result == ((n) * (n) - (a));
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t a)
{
    // Variable declarations at scope top
    int32_t result;
    
    //@ assert 1 <= n <= 100;
    //@ assert 0 <= a <= n * n;
    
    //@ assert n * n <= 10000;
    //@ assert n * n >= a;
    
    result = (int32_t)(n * n - a);
    
    //@ assert result == ((n) * (n) - (a));
    return result;
}
