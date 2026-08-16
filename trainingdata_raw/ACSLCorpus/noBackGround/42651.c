#include <stdint.h>
/*@
    requires 2 <= n && n <= 100;
    ensures \result == (n / 2) * ((n + 1) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    uint64_t half_n;
    uint64_t next_even;
    uint64_t ans;
    
    half_n = n / 2;
    //@ assert (2 <= ((integer)n) && ((integer)n) <= 100 && ((integer)half_n) == ((integer)n) / 2 && ((integer)half_n) <= 50);
    
    next_even = (n + 1) / 2;
    //@ assert (2 <= ((integer)n) && ((integer)n) <= 100 && ((integer)next_even) == (((integer)n) + 1) / 2 && ((integer)next_even) <= 50);
    
    //@ assert (((integer)half_n) * ((integer)next_even) <= 2500);
    
    ans = half_n * next_even;
    return ans;
}
