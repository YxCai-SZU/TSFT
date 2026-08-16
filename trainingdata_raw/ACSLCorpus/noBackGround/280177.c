#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000);
    ensures \result == (((n) * ((n) - 1)) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    // Variable declarations at scope top
    uint64_t result;
    
    //@ assert n > 0;
    //@ assert n <= 1000000000;
    //@ assert n * (n - 1) <= 1000000000 * 999999999;
    //@ assert (n * (n - 1)) / 2 <= 500000000 * 999999999;
    
    result = (n * (n - 1)) / 2;
    return result;
}
