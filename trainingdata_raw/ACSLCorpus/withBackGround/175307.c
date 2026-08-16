#include <stdint.h>

/*@ predicate valid_params(integer a, integer b, integer c, integer k) =
    (1 <= a <= 100) && (1 <= b <= 100) && (1 <= c <= 100) && (1 <= k <= 3);
*/

/*@
    requires valid_params(a, b, c, k);
    ensures \result <= k;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t k) {
    uint32_t ans;
    ans = 0;
    
    if (k >= a) {
        ans = ans + a;
        //@ assert ans <= k;
        if (k - a >= b) {
            //@ assert ans <= k;
            if (k - a - b >= c) {
                ans = ans - c;
                //@ assert ans <= k;
            } else {
                ans = ans - (k - a - b);
                //@ assert ans <= k;
            }
        }
    } else {
        ans = ans + k;
        //@ assert ans <= k;
    }
    
    //@ assert ans <= k;
    return ans;
}
