#include <stdint.h>

/*@
    requires 1 <= k <= 999;
    ensures \result == (long)((k / 2) * (k - k / 2));
    assigns \nothing;
*/
int64_t func(uint64_t k)
{
    // Variable declarations at scope top
    uint64_t a;
    uint64_t b;
    uint64_t result;
    
    //@ assert 1 <= k <= 999;
    
    a = k / 2;
    b = k - (k / 2);
    
    //@ assert a * b <= 999 * 499;
    
    //@ assert a * b == (k / 2) * (k - k / 2);
    
    result = a * b;
    return (int64_t)result;
}
