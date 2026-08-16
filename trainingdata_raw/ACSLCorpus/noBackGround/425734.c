#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 100);
    ensures \result == ((x) * (x));
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    // Variable declarations at top
    uint64_t result;

    //@ assert 1 <= x && x <= 100;
    //@ assert ((x) * (x)) <= 10000;
    
    result = x * x;
    
    //@ assert result == ((x) * (x));
    return result;
}
