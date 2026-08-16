#include <stdint.h>

/*@
    requires (1 <= (n) <= 1000000000000 &&
        1 <= (m) <= 1000000000000);
    ensures \result <= n + m;
    ensures \result >= ((n) >= (m) ? (n) - (m) : 0);
*/
uint64_t func(uint64_t n, uint64_t m) {
    // Declare all variables at the top
    uint64_t res;

    //@ assert (1 <= (n) <= 1000000000000 &&         1 <= (m) <= 1000000000000);
    
    if (n > m) {
        //@ assert n > m;
        //@ assert n - m >= 0;
        //@ assert n - m <= n + m;
        res = n - m;
    } else {
        //@ assert n <= m;
        res = 0;
    }
    
    return res;
}
