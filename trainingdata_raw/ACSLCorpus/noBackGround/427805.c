#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures ((\result) >= 0);
    ensures ((a) >= 10 * (b) ==> (\result) == 1);
    ensures ((a) < 10 * (b) ==> (\result) == 0);
*/
int32_t func(uint32_t a, uint32_t b) {
    uint32_t c;
    int32_t result;

    c = b * 10;
    
    if (a < c) {
        //@ assert a < 10 * b;
        result = 0;
    } else {
        //@ assert a >= 10 * b;
        result = 1;
    }
    
    return result;
}
