#include <stdint.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    ensures \result == a - 2 * b || \result == 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    // Variable declarations at top of scope
    int64_t ret;
    
    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    
    if (a - 2 * b > 0) {
        //@ assert a - 2 * b >= 0;
        ret = a - 2 * b;
    } else {
        //@ assert 0 >= 0;
        ret = 0;
    }
    
    //@ assert ret == a - 2 * b || ret == 0;
    //@ assert ret >= 0;
    
    return ret;
}
