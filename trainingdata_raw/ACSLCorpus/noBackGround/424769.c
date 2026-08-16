#include <stdint.h>

/*@
    requires 1 <= n <= 10000;
    requires 1 <= x <= 10000;
    requires 1 <= t <= 10000;
    ensures \result == (((n) / (x) + 1) * (t)) || 
            \result == (((n) / (x)) * (t));
*/
uint64_t func(uint64_t n, uint64_t x, uint64_t t) {
    uint64_t result;
    
    if (n > x) {
        //@ assert n / x <= 10000;
        //@ assert n / x + 1 <= 10001;
        //@ assert (n / x + 1) * t <= 10001 * 10000;
        result = (n / x + 1) * t;
    } else {
        //@ assert n / x <= 10000;
        //@ assert (n / x) * t <= 10000 * 10000;
        result = (n / x) * t;
    }
    
    return result;
}
