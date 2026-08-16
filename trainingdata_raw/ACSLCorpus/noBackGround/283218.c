#include <stdint.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> (((x) / 100) * 100 + 100 - (x)) > 0;
    ensures \result == 0 ==> (((x) / 100) * 100 + 100 - (x)) <= 0;
*/
uint32_t func(uint32_t x) {
    uint32_t n;
    uint32_t res;
    
    //@ assert x / 100 <= 1000;
    //@ assert (x / 100) * 100 <= 100000;
    //@ assert (x / 100) * 100 + 100 <= 101000;
    
    n = x / 100;
    res = x + 100 - n * 100;
    
    if (res > 0) {
        return 1;
    } else {
        return 0;
    }
}
