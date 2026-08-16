#include <stdint.h>

/*@
    requires 0 <= n <= 1000000000000000;
    requires 0 <= m <= 1000000000000000;
    requires n <= m;
    ensures \result >= 0;
    ensures \result <= m;
    ensures \result == m / 2 || \result == m / 2 + 1;
*/
uint64_t func(uint64_t n, uint64_t m) {
    uint64_t result;
    
    if (m / 2 >= n) {
        //@ assert m / 2 >= 0;
        result = m / 2;
    } else {
        //@ assert m / 2 + 1 >= 0;
        result = m / 2 + 1;
    }
    
    //@ assert result >= 0;
    //@ assert result <= m;
    //@ assert result == m / 2 || result == m / 2 + 1;
    
    return result;
}
