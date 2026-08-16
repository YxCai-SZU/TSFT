#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (2 * (n) * 3);
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    int64_t pi;
    int64_t result;
    
    pi = 3;
    result = 2 * n * pi;
    
    //@ assert result == 2 * n * 3;
    
    return result;
}
