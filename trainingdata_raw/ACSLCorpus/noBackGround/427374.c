#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000);
    ensures \result == ((n) * ((n) - 1) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    uint64_t result;
    
    //@ assert (1 <= (n) && (n) <= 1000000000);
    
    if (n < 1 || n > 1000000000) {
        //@ assert n < 1 || n > 1000000000;
        result = 0;
        return result;
    }
    
    //@ assert ((n) * ((n) - 1) / 2) <= 9223372036854775807 / 2;
    
    result = n * (n - 1) / 2;
    //@ assert result == ((n) * ((n) - 1) / 2);
    return result;
}
