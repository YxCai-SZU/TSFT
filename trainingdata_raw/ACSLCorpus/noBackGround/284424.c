#include <stdint.h>

/*@
    requires ((a) < 0x80000000 && (b) < 0x80000000 && (c) < 0x80000000 &&
        (d) < 0x80000000 && (e) < 0x80000000 && (k) < 0x80000000 &&
        (uint64_t)(a) + (uint64_t)(b) + (uint64_t)(c) + (uint64_t)(d) + (uint64_t)(e) <= (uint64_t)(k));
    ensures \result == ((k) - (a) - (b) - (c) - (d) - (e));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t k)
{
    uint32_t res;

    //@ assert a + b + c + d + e <= k;
    
    res = k - a - b - c - d - e;
    
    //@ assert res == k - a - b - c - d - e;
    
    return res;
}
