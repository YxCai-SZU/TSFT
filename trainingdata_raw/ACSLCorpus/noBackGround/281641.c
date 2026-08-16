#include <stdint.h>

/*@
    requires 1 <= n <= 1000000000000000000;
    requires 1 <= k <= 1000000000000000000;
    ensures ((n) % (k) == 0) ==> \result == 0;
    ensures ((n) % (k) != 0) ==> \result == 1;
*/
uint64_t func(uint64_t n, uint64_t k) {
    uint64_t res;
    
    if (n % k == 0) {
        //@ assert ((n) % (k) == 0);
        res = 0;
    } else {
        //@ assert ((n) % (k) != 0);
        res = 1;
    }
    
    return res;
}
