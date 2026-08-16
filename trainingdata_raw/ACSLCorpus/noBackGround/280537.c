#include <stdint.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (a) <= 50 && 1 <= (b) <= 50);
    ensures \result == (((n) - 1) * (a) > (b) ? (b) : ((n) - 1) * (a));
    ensures \result == (n - 1) * a || \result == b;
    ensures \result <= b;
*/
uint64_t func(uint64_t n, uint64_t a, uint64_t b) {
    uint64_t result;
    
    //@ assert 1 <= n <= 20 && 1 <= a <= 50 && 1 <= b <= 50;
    
    //@ assert (n - 1) * a <= 50 * 50;
    
    result = (n - 1) * a;
    
    if (result > b) {
        //@ assert result == (n - 1) * a;
        //@ assert result > b;
        result = b;
        //@ assert result == b;
    } else {
        //@ assert result == (n - 1) * a;
        //@ assert result <= b;
    }
    
    //@ assert result == (((n) - 1) * (a) > (b) ? (b) : ((n) - 1) * (a));
    return result;
}
