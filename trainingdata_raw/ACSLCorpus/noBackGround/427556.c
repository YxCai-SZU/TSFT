#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10000 &&
        1 <= (b) && (b) <= 10000 &&
        1 <= (c) && (c) <= 10000 &&
        1 <= (d) && (d) <= 10000);
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t max_val;
    uint32_t max_val2;
    uint32_t ans;

    max_val = (a > b) ? a : b;
    //@ assert max_val == a || max_val == b;

    max_val2 = (c > d) ? c : d;
    //@ assert max_val2 == c || max_val2 == d;

    ans = max_val + max_val2;
    //@ assert ans == a + c || ans == a + d || ans == b + c || ans == b + d;
    
    return ans;
}
