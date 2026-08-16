#include <stdint.h>

/*@
    requires (1 <= (x) <= 1000000000000);
    ensures \result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t g;
    uint64_t k;
    uint64_t g_value;
    uint64_t k_value;
    uint64_t res;

    //@ assert (1 <= (x) <= 1000000000000);
    
    g = x / 500;
    //@ assert g <= 2000000000;
    
    k = x % 500;
    //@ assert k < 500;
    
    g_value = g * 1000;
    //@ assert g_value <= 2000000000000;
    
    k_value = (k / 5) * 5;
    //@ assert k_value <= 500;
    
    res = g_value + k_value;
    //@ assert res == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    
    return res;
}
