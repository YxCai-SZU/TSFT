#include <stdint.h>

/*@
    requires (0 <= (a) <= 1000000000000000 &&
        0 <= (b) < 1000);
    ensures \result == (a * b) / 100;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b)
{
    //@ assert (0 <= (a) <= 1000000000000000 &&         0 <= (b) < 1000);
    //@ assert ((a) * (b)) <= 18446744073709551615;
    
    uint64_t result;
    result = (a * b) / 100;
    
    //@ assert result == (a * b) / 100;
    return result;
}
