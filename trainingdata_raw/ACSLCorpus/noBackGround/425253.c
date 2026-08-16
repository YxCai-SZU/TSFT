#include <stdint.h>

/*@
    requires (1 <= (A) && (A) <= 10000 &&
        1 <= (B) && (B) <= 10000);
    ensures \result >= 0;
    ensures \result <= A;
    assigns \nothing;
*/
uint32_t func(uint32_t A, uint32_t B)
{
    uint32_t ans;
    //@ assert (1 <= (A) && (A) <= 10000 &&         1 <= (B) && (B) <= 10000);
    
    if (A > B)
    {
        ans = A - B;
    }
    else
    {
        ans = 0;
    }
    
    //@ assert ans == ((A) > (B) ? (A) - (B) : 0);
    //@ assert ans >= 0;
    //@ assert ans <= A;
    
    return ans;
}
