#include <stdint.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t result = 0;
    uint64_t r1 = 0;

    //@ assert 1 <= x <= 100000;
    result = (x / 500) * 1000;
    r1 = x % 500;
    
    //@ assert r1 / 5 * 5 <= 5000;
    result = result + (r1 / 5) * 5;
    
    //@ assert result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    return result;
}
