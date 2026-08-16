#include <stdint.h>

/*@
    requires (0 <= (a) && 0 <= (b) && 0 <= (c) && 1 <= (k) && (k) <= (a) + (b) + (c));
    ensures \result <= a;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t sum = 0;
    int32_t remaining_k = k;
    
    //@ assert (0 <= (a) && 0 <= (b) && 0 <= (c) && 1 <= (k) && (k) <= (a) + (b) + (c));
    
    if (remaining_k <= a) {
        sum += remaining_k;
        //@ assert sum == remaining_k;
    } else {
        sum += a;
        remaining_k -= a;
        //@ assert sum == a && remaining_k == k - a;
        
        if (remaining_k <= b) {
            // do nothing
        } else {
            remaining_k -= b;
            //@ assert remaining_k == k - a - b;
            sum -= remaining_k;
            //@ assert sum == a - (k - a - b);
        }
    }
    
    //@ assert sum <= a;
    return sum;
}
