#include <stdint.h>

/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20);
    assigns \nothing;
    ensures (((a) < 10 && (b) < 10) ==> \result == ((a) * (b))) && 
            (((a) >= 10 || (b) >= 10) ==> \result == -1);
*/
int32_t func(uint32_t a, uint32_t b) {
    int32_t result;
    
    if (a < 10 && b < 10) {
        //@ assert a >= 1 && a <= 9;
        //@ assert b >= 1 && b <= 9;
        //@ assert ((a) * (b)) <= 81;
        result = (int32_t)(a * b);
    } else {
        //@ assert a >= 10 || b >= 10;
        result = -1;
    }
    
    return result;
}
