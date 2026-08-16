#include <stdint.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (((x) / 100) * 5 + (x) % 100) >= 2050;
    ensures \result == 0 ==> (((x) / 100) * 5 + (x) % 100) < 2050;
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    // Variable declarations at scope top
    int32_t res;
    uint32_t n;
    
    //@ assert (1 <= (x) <= 100000);
    
    // Arithmetic safety assertions
    //@ assert x / 100 <= 1000;
    //@ assert (x / 100) * 5 <= 5000;
    //@ assert x % 100 <= 100;
    //@ assert (x / 100) * 5 + x % 100 <= 5100;
    
    n = (x / 100) * 5 + x % 100;
    
    if (n >= 2050) {
        //@ assert n >= 2050;
        res = 1;
    } else {
        //@ assert n < 2050;
        res = 0;
    }
    
    return res;
}
