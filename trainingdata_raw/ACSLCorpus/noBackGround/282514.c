#include <stdint.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (a) <= 50 && 1 <= (b) <= 50);
    ensures \result == n * a || \result == b;
    ensures \result <= b;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t a, uint64_t b)
{
    //@ assert (1 <= (n) <= 20 && 1 <= (a) <= 50 && 1 <= (b) <= 50);
    
    uint64_t result;
    
    //@ assert n * a <= 20 * 50;
    
    if (n * a < b)
    {
        result = n * a;
    }
    else
    {
        result = b;
    }
    
    //@ assert result == n * a || result == b;
    //@ assert result <= b;
    
    return result;
}
