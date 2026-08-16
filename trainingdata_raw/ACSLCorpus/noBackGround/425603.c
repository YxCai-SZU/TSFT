#include <stdint.h>

/*@
    requires (1 <= (A) <= 100 &&
        1 <= (B) <= 100 &&
        1 <= (H) <= 100 &&
        (H) % 2 == 0);
    ensures \result == (((A) + (B)) * (H) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t A, uint32_t B, uint32_t H)
{
    // Variable declarations at scope top
    uint32_t ans;

    //@ assert A + B <= 200;
    //@ assert (A + B) * H <= 20000;
    
    ans = (A + B) * H / 2;
    return ans;
}
