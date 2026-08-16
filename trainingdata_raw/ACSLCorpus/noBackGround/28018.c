#include <stdint.h>

/*@
    requires (101 <= (x) && (x) <= 100000000000000000);
    assigns \nothing;
    ensures ((\result) >= 0 && (\result) <= (x) - 100 &&
        (\result) == ((x) - 100) / 100);
*/
uint64_t func(uint64_t x)
{
    // Variable declarations at scope top
    uint64_t result;
    
    //@ assert x >= 101;
    //@ assert x <= 100000000000000000;
    //@ assert x - 100 >= 0;
    //@ assert x - 100 <= 100000000000000000;
    
    result = (x - 100) / 100;
    return result;
}
