#include <stdint.h>

/*@
    requires (1 <= (k) <= 200);
    ensures \result == ((((k)) / 2) * ((((k)) + 1) / 2) * 10000 / 2);
    assigns \nothing;
*/
uint64_t func(uint32_t k)
{
    uint32_t n;
    uint32_t m;
    uint64_t ans;
    
    n = k / 2;
    m = (k + 1) / 2;
    
    //@ assert n <= 100 && m <= 100;
    //@ assert n * m <= 10000;
    //@ assert n * m * 10000 <= 100000000;
    
    ans = (uint64_t)(n * m * 10000) / 2;
    
    return ans;
}
