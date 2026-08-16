#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((r) * 6);
    assigns \nothing;
*/
int32_t func(int32_t r)
{
    int32_t pi;
    int32_t result;
    
    //@ assert (1 <= (r) <= 100);
    pi = 3;
    result = r * 2 * pi;
    
    //@ assert pi == 3;
    //@ assert result == r * 2 * pi;
    //@ assert result == r * 6;
    
    return result;
}
