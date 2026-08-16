#include <stdint.h>

/*@
    requires n * n <= 0xFFFFFFFF;
    ensures \result == n * n;
    ensures (((n) * (n)) == (\result));
    ensures (0 <= (\result) <= 0xFFFFFFFF);
*/
uint32_t find_square_num(uint32_t n) {
    // Variable declarations at top
    uint32_t result;
    
    //@ assert n * n <= 0xFFFFFFFF;
    //@ assert n * n >= 0;
    //@ assert n * n <= 0xFFFFFFFF;
    //@ assert n * n >= 0;
    
    result = n * n;
    
    //@ assert result == n * n;
    //@ assert result >= 0 && result <= 0xFFFFFFFF;
    
    return result;
}

