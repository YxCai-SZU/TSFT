#include <stdint.h>

/*@
    requires (2 <= (n) <= 100 && 2 <= (m) <= 100);
    ensures \result == ((((n)) * ((m))) - (((n)) + ((m)) - 1));
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    uint32_t max_val;
    uint32_t min_val;
    int32_t result;

    //@ assert (2 <= (n) <= 100 && 2 <= (m) <= 100);
    
    //@ assert ((n) * (m)) <= 10000;
    max_val = n * m;
    
    //@ assert ((n) + (m) - 1) <= 199;
    min_val = n + m - 1;
    
    //@ assert ((n) * (m)) >= ((n) + (m) - 1);
    result = (int32_t)max_val - (int32_t)min_val;
    
    //@ assert result == ((((n)) * ((m))) - (((n)) + ((m)) - 1));
    return result;
}
