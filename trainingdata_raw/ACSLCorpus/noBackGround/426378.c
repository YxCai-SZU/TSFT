#include <stdint.h>

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    requires a != b;
    ensures \result == 6 - a - b;
    ensures 1 <= \result <= 3;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b)
{
    uint64_t ans;
    
    //@ assert 1 <= a + b <= 6;
    //@ assert 0 <= 6 - a - b <= 5;
    
    ans = 6 - a - b;
    
    //@ assert ans == 6 - a - b;
    //@ assert 1 <= ans <= 3;
    
    return ans;
}
