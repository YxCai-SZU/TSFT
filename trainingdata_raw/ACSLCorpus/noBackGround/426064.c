#include <stdint.h>

/*@
    requires (1 <= (A) <= 10000) && (1 <= (B) <= 10000) && 
             (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    ensures \result == ((A) * (B)) || \result == ((C) * (D));
    ensures \result >= ((A) * (B));
    ensures \result >= ((C) * (D));
    assigns \nothing;
*/
uint32_t func(uint32_t A, uint32_t B, uint32_t C, uint32_t D)
{
    uint32_t sa;
    uint32_t sc;
    uint32_t ans;

    //@ assert ((A) * (B)) <= 10000 * 10000;
    sa = A * B;
    
    //@ assert ((C) * (D)) <= 10000 * 10000;
    sc = C * D;

    if (sa > sc) {
        ans = sa;
    } else {
        ans = sc;
    }

    //@ assert ans == ((A) * (B)) || ans == ((C) * (D));
    //@ assert ans >= ((A) * (B));
    //@ assert ans >= ((C) * (D));

    return ans;
}
