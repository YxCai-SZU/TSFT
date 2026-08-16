#include <stdint.h>

/*@
    requires (1 <= (a) <= 3) && (1 <= (b) <= 3) && ((a) != (b));
    ensures \result == (6 - (a) - (b));
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b) {
    int32_t c;
    //@ assert (1 <= (a) <= 3) && (1 <= (b) <= 3) && ((a) != (b));
    c = 6 - (int32_t)a - (int32_t)b;
    
    if (c == 1) {
        //@ assert c == 1;
        return 1;
    } else if (c == 2) {
        //@ assert c == 2;
        return 2;
    } else if (c == 3) {
        //@ assert c == 3;
        return 3;
    }
    
    //@ assert c == 1 || c == 2 || c == 3;
    return -1;
}
