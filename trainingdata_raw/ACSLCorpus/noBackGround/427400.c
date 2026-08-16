#include <stdint.h>

/*@
    requires (0 <= (v0) <= 1000000000000000000) && (0 <= (v1) <= 1000000000000000000);
    requires (0 <= (w0) <= 1000000000000000000) && (0 <= (w1) <= 1000000000000000000);
    ensures \result >= 0;
    ensures \result == v1 * w0 || \result == v0 * w1;
*/
int64_t func(int64_t v0, int64_t v1, int64_t w0, int64_t w1) {
    int64_t x;
    int64_t y;
    int64_t ans;
    
    //@ assert v1 * w0 >= 0;
    x = v1 * w0;
    
    //@ assert v0 * w1 >= 0;
    y = v0 * w1;
    
    if (x > y) {
        ans = x;
    } else {
        ans = y;
    }
    
    return ans;
}
