#include <stdint.h>

/*@
    requires (0 <= (x) <= 100);
    assigns \nothing;
    ensures \result == ((x) * 2 * 3);
*/
int32_t func(int32_t x)
{
    int32_t pi;
    int32_t result;
    
    pi = 3;
    
    //@ assert pi == 3;
    //@ assert x * 2 * pi == x * 2 * 3;
    
    result = x * 2 * pi;
    return result;
}
