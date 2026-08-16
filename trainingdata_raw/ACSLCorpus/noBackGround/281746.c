#include <stdint.h>

/*@
    requires 1 <= a && a <= 10;
    ensures \result == a + a * a + a * a * a;
    assigns \nothing;
*/
uint64_t func(uint64_t a)
{
    uint64_t a2;
    uint64_t a3;
    uint64_t ans;
    
    //@ assert a * a <= 100;
    a2 = a * a;
    
    //@ assert a * a * a <= 1000;
    a3 = a * a * a;
    
    //@ assert a + a2 + a3 <= 1110;
    ans = a + a2 + a3;
    
    return ans;
}
