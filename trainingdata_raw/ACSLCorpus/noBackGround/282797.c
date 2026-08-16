#include <stdint.h>

/*@
    requires (1 <= (n) <= 10000);
    ensures \result == ((1000 - (((n)) % 1000)) % 1000);
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    uint32_t remainder;
    uint32_t result;

    //@ assert (1 <= (n) <= 10000);
    remainder = n % 1000;
    
    //@ assert remainder == ((n) % 1000);
    result = (1000 - remainder) % 1000;
    
    //@ assert result == ((1000 - (((n)) % 1000)) % 1000);
    return result;
}
