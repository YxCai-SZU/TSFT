#include <stdint.h>

/*@
    requires ((1 <= ((a)) <= 100) && (1 <= ((b)) <= 100));
    ensures \result == ((a) <= 2 * (b) ? 0 : (a) - 2 * (b));
    ensures \result >= 0;
    ensures \result == 0 || \result == (int)(a - 2 * b);
*/
int32_t func(uint32_t a, uint32_t b) {
    int32_t result;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    
    if (a <= 2 * b) {
        result = 0;
        //@ assert result == 0;
        //@ assert result == ((a) <= 2 * (b) ? 0 : (a) - 2 * (b));
    } else {
        //@ assert a > 2 * b;
        //@ assert a - 2 * b >= 0;
        result = (int32_t)(a - 2 * b);
        //@ assert result == a - 2 * b;
        //@ assert result == ((a) <= 2 * (b) ? 0 : (a) - 2 * (b));
    }
    
    //@ assert result >= 0;
    //@ assert result == 0 || result == (int)(a - 2 * b);
    return result;
}
