#include <stdint.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
*/
uint64_t func(uint64_t x)
{
    uint64_t n_500;
    uint64_t n_5;
    uint64_t result;
    
    //@ assert (1 <= (x) <= 100000);
    
    n_500 = x / 500;
    //@ assert n_500 == ((x) / 500);
    
    n_5 = (x - 500 * n_500) / 5;
    //@ assert n_5 == (((x) - 500 * ((x) / 500)) / 5);
    
    result = n_500 * 1000 + n_5 * 5;
    //@ assert result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    
    return result;
}
