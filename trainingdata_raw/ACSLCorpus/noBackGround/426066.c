#include <stdint.h>

/*@
    requires (1 <= (a) <= 20 && 1 <= (b) <= 20);
    ensures
        (a < 10 && b < 10 ==> \result == (int)(a * b)) &&
        (a >= 10 || b >= 10 ==> \result == -1);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t ret;
    
    //@ assert (1 <= (a) <= 20 && 1 <= (b) <= 20);
    //@ assert 1 <= a * b <= 400;
    
    if (a < 10 && b < 10) {
        ret = (int32_t)(a * b);
        //@ assert ret == (int)(a * b);
    } else {
        ret = -1;
        //@ assert ret == -1;
    }
    
    return ret;
}
