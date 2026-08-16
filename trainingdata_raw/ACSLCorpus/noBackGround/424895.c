#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == 2 * n * 3;
    assigns \nothing;
*/
int32_t func(int32_t n)
{
    int32_t pi;
    int32_t result;
    
    pi = 3;
    
    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert 2 * n <= 200;
    //@ assert 2 * n * pi <= 600;
    
    result = 2 * n * pi;
    return result;
}
