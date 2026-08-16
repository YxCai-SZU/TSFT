#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == 0 || \result == 1;
    ensures \result == (((n) % 2 == 0) ? 1 : 0);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t result;
    
    //@ assert (1 <= (n) && (n) <= 100);
    
    if ((n % 2U) == 0U) {
        result = 1;
    } else {
        result = 0;
    }
    
    //@ assert result == (((n) % 2 == 0) ? 1 : 0);
    
    return result;
}
