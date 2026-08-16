#include <stdint.h>

/*@ predicate is_valid_range(integer x) = 1 <= x <= 100000; */

/*@
    requires is_valid_range(x);
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> x * x * x <= 50000000000;
*/
int32_t func(uint64_t x) {
    // Variable declarations at top of scope
    uint64_t n;
    uint64_t n1;
    int32_t result;

    //@ assert 1 <= x <= 100000;
    //@ assert x * x <= 100000 * 100000;
    //@ assert x * x * x <= 100000 * 100000 * 100000;

    n = x * x;
    n1 = n * x;
    
    if (n1 <= 50000000000) {
        result = 1;
    } else {
        result = 0;
    }
    
    return result;
}
