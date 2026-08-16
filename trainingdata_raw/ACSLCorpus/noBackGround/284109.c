#include <stdint.h>
/*@
    requires 1 <= n <= 1000000000000000000;
    requires 1 <= k <= 1000000000000000000;
    ensures \result <= 1;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t k) {
    uint64_t res;
    //@ ghost uint64_t original_n = n;
    //@ ghost uint64_t original_k = k;
    
    if (n % k == 0) {
        //@ assert ((original_n) % (original_k) == 0);
        res = 0;
    } else {
        //@ assert ((original_n) % (original_k) != 0);
        //@ assert 1 <= 1;
        res = 1;
    }
    
    //@ assert res <= 1;
    return res;
}
