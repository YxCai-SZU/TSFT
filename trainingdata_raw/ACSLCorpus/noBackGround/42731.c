#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b)
{
    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100);
    //@ assert 1 <= ((a) * (b)) <= 10000;
    
    uint64_t ans;
    ans = a * b;
    
    //@ assert ans == ((a) * (b));
    return ans;
}
