#include <stdint.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    ensures (a - b >= c) ==> \result == 0;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c) {
    int32_t x;
    int32_t result;

    //@ assert a - b >= 0;
    //@ assert a - b <= 20;
    
    x = a - b;
    
    if (x < c) {
        //@ assert x < c;
        result = c - x;
        //@ assert result == (((a) - (b) < (c)) ? ((c) - ((a) - (b))) : 0);
    } else {
        //@ assert x >= c;
        result = 0;
        //@ assert result == (((a) - (b) < (c)) ? ((c) - ((a) - (b))) : 0);
    }
    
    return result;
}
