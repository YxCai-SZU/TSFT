#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 &&
        0 <= (aa) <= (n) * (n));
    ensures \result == ((n) * (n) - (aa));
    ensures \result >= 0;
*/
int32_t func(int32_t n, int32_t aa) {
    // Variable declarations at top of scope
    int32_t result;
    
    //@ assert 1 <= n <= 100;
    //@ assert 0 <= aa <= n * n;
    //@ assert n * n <= 10000;
    //@ assert n * n - aa >= 0;
    
    result = n * n - aa;
    
    //@ assert result == ((n) * (n) - (aa));
    //@ assert result >= 0;
    
    return result;
}
