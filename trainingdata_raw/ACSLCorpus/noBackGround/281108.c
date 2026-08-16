#include <stdint.h>

/*@
    requires (1 <= (B) && (B) <= (A) && (A) <= 20 &&
        1 <= (C) && (C) <= 20);
    ensures \result >= 0 && \result <= C;
    assigns \nothing;
*/
int64_t func(int64_t A, int64_t B, int64_t C)
{
    int64_t ans;
    int64_t raw_val;
    
    //@ assert B - 1 >= 0;
    raw_val = C - (A - B) * 2;
    
    if (raw_val < 0) {
        ans = 0;
    } else {
        if (raw_val < C) {
            ans = raw_val;
        } else {
            ans = C;
        }
    }
    
    //@ assert ans <= C;
    
    return ans;
}
