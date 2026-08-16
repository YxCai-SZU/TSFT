#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == a + c || \result == b + c || \result == a + d || \result == b + d;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t max_ab;
    uint32_t max_cd;
    uint32_t ans;
    
    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    
    if (a > b) {
        max_ab = a;
    } else {
        max_ab = b;
    }
    
    if (c > d) {
        max_cd = c;
    } else {
        max_cd = d;
    }
    
    ans = max_ab + max_cd;
    
    //@ assert ans == ((a) > (b) ? (a) : (b)) + ((c) > (d) ? (c) : (d));
    //@ assert ans == a + c || ans == b + c || ans == a + d || ans == b + d;
    
    return ans;
}
