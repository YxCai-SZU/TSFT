#include <stdint.h>

/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20);
    ensures (a <= 9 && b <= 9 ==> \result == a * b);
    ensures (a > 9 || b > 9 ==> \result == -1);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t ans;
    //@ assert 1 <= a <= 20;
    //@ assert 1 <= b <= 20;
    //@ assert a * b <= 400;
    
    if (a > 9 || b > 9) {
        ans = -1;
    } else {
        ans = (int32_t)(a * b);
    }
    
    return ans;
}
