#include <stdint.h>

/*@
    requires (2 <= (a) && (a) <= 100) && (2 <= (b) && (b) <= 100);
    ensures \result == (((a) - 1) * ((b) - 1));
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b) {
    uint32_t a_unsigned;
    uint32_t b_unsigned;
    uint32_t ans;
    
    a_unsigned = (uint32_t)a;
    b_unsigned = (uint32_t)b;
    
    //@ assert a_unsigned - 1 >= 1;
    //@ assert b_unsigned - 1 >= 1;
    //@ assert (a_unsigned - 1) * (b_unsigned - 1) <= 99 * 99;
    
    ans = (a_unsigned - 1) * (b_unsigned - 1);
    return (int32_t)ans;
}
