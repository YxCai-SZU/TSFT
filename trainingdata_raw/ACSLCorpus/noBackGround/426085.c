#include <stdint.h>

/*@
    requires (1 <= (A) && (A) <= 20 &&
        1 <= (B) && (B) <= 20 &&
        1 <= (T) && (T) <= 20);
    ensures \result == (((T) / (A)) * (B));
    assigns \nothing;
*/
uint32_t func(uint32_t A, uint32_t B, uint32_t T)
{
    uint32_t ans;
    
    //@ assert 1 <= A && A <= 20;
    //@ assert 1 <= B && B <= 20;
    //@ assert 1 <= T && T <= 20;
    //@ assert T / A <= 20;
    //@ assert (T / A) * B <= 400;
    
    ans = (T / A) * B;
    
    return ans;
}
