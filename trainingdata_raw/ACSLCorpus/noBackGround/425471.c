#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 100) && (2 <= (b) && (b) <= 1000) && ((b) % 2 == 0);
    ensures \result <= b;
    ensures a >= 13 ==> \result == b;
    ensures a <= 5 ==> \result == 0;
    ensures a >= 6 && a <= 12 ==> \result == b / 2;
*/
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t ans;
    
    if (a >= 13) {
        ans = b;
    } else if (a >= 6) {
        ans = b / 2;
    } else {
        ans = 0;
    }
    
    //@ assert ans <= b;
    //@ assert a >= 13 ==> ans == b;
    //@ assert a <= 5 ==> ans == 0;
    //@ assert a >= 6 && a <= 12 ==> ans == b / 2;
    
    return ans;
}
