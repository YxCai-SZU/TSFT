#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result >= 0 && \result <= 500;
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t res;
    uint32_t n_unsigned;
    uint32_t res_unsigned;
    
    //@ assert (1 <= (n) && (n) <= 100);
    
    if (n % 2 == 0) {
        res = 0;
        //@ assert res == 0;
    } else {
        n_unsigned = n;
        //@ assert n_unsigned == n;
        res_unsigned = (n_unsigned * 500U) / 100U;
        //@ assert res_unsigned == (((n) % 2 == 0) ? 0 : ((n) * 500 / 100));
        //@ assert res_unsigned <= 500;
        res = (int32_t)res_unsigned;
    }
    
    //@ assert res >= 0 && res <= 500;
    return res;
}
