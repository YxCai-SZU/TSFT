#include <stdint.h>

/*@
    requires (1 <= (k) <= (n) <= 50);
    ensures \result == ((n) == 1 ? 0 :
        (k) == 1 ? (n) - 1 :
        (n) - 1 + ((k) - 1) / 2);
    assigns \nothing;
*/
int64_t func(uint32_t n, uint32_t k)
{
    int64_t ans;
    //@ assert (1 <= (k) <= (n) <= 50);
    
    if (n == 1) {
        ans = 0;
    } else if (k == 1) {
        ans = (int64_t)n - 1;
    } else {
        //@ assert (k - 1) / 2 <= 24;
        //@ assert n - 1 <= 49;
        ans = (int64_t)(n - 1 + (k - 1) / 2);
    }
    
    return ans;
}
