#include <stdint.h>

/*@
    requires (2 <= (a) && (a) <= 100) && (2 <= (b) && (b) <= 100);
    ensures \result == (((a) - 1) * ((b) - 1));
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b) {
    int32_t result;
    
    //@ assert a > 1;
    //@ assert b > 1;
    //@ assert (((a) - 1) * ((b) - 1)) >= 0;
    //@ assert (((a) - 1) * ((b) - 1)) <= (((100) - 1) * ((100) - 1));
    //@ assert (((a) - 1) * ((b) - 1)) == (((a) - 1) * ((b) - 1));
    
    result = (a - 1) * (b - 1);
    return result;
}
