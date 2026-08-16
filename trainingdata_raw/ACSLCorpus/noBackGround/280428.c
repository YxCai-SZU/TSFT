#include <stdint.h>

/*@
    requires 1 <= x <= 23;
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    int32_t a;
    int32_t b;
    int32_t c;
    int32_t ret;

    //@ assert (1 <= (x) <= 23);
    
    a = (x < 10) ? 1 : 0;
    //@ assert a == (((x) < 10) ? 1 : 0);
    
    b = (x > 19) ? 1 : 0;
    //@ assert b == (((x) > 19) ? 1 : 0);
    
    c = (x > 9 && x < 20) ? 1 : 0;
    //@ assert c == (((x) > 9 && (x) < 20) ? 1 : 0);
    
    if (a == 1) {
        //@ assert a == 1;
        ret = 1;
    } else if (b == 1) {
        //@ assert b == 1;
        ret = 0;
    } else if (c == 1) {
        //@ assert c == 1;
        ret = 0;
    } else {
        //@ assert a == 0 && b == 0 && c == 0;
        ret = 1;
    }
    
    //@ assert ret == 0 || ret == 1;
    return ret;
}
