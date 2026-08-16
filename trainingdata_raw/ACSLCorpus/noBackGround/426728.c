#include <stdint.h>

/*@
    requires (1 <= (N) && (N) <= 100000000000000000 &&
        1 <= (K) && (K) <= 100000000000000000);
    ensures \result <= 1;
    assigns \nothing;
*/
uint64_t func(uint64_t N, uint64_t K) {
    uint64_t r;
    
    //@ assert N <= 100000000000000000;
    //@ assert K <= 100000000000000000;
    
    r = N % K;
    
    //@ assert r <= 100000000000000000;
    
    if (r == 0) {
        return 0;
    } else {
        //@ assert 1 <= 1;
        return 1;
    }
}
