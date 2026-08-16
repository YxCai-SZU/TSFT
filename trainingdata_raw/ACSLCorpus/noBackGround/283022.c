#include <stdint.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    ensures \result == (n - 1) * (m - 1);
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t m)
{
    // Declare all variables at the top
    uint32_t result;

    //@ assert n > 0 && n <= 100;
    //@ assert m > 0 && m <= 100;
    
    //@ assert n - 1 >= 0;
    //@ assert m - 1 >= 0;
    
    //@ assert (n - 1) <= 99;
    //@ assert (m - 1) <= 99;

    //@ assert (n - 1) * (m - 1) <= 99 * 99;

    result = (n - 1) * (m - 1);
    
    //@ assert result == (n - 1) * (m - 1);
    
    return result;
}
