#include <stdint.h>

/*@
    requires (0 <= (n) <= 100) && (0 <= (m) <= 100);
    ensures \result == (((n) * (100 - (m)) / 100) + (m));
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    // Declare all variables at scope top
    uint64_t coffee;
    uint64_t result;

    //@ assert (0 <= (n) <= 100) && (0 <= (m) <= 100);
    
    // Calculate coffee that doesn't get thrown away
    //@ assert n * (100 - m) <= 10000;
    coffee = n * (100 - m) / 100;
    
    // Add the coffee that gets added to total
    result = coffee + m;
    
    //@ assert result == (((n) * (100 - (m)) / 100) + (m));
    return result;
}
