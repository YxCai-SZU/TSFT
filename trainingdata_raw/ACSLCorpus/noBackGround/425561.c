#include <stdint.h>

/*@
    requires 1 <= x <= 100000;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (((x) / 100) * 100 + 100 == (x));
    ensures \result == 0 ==> !(((x) / 100) * 100 + 100 == (x));
*/
int32_t func(uint32_t x)
{
    int32_t ans;
    //@ assert 1 <= x <= 100000;
    
    if ((x / 100) * 100 + 100 == x) {
        ans = 1;
        //@ assert ans == 1;
        //@ assert (((x) / 100) * 100 + 100 == (x));
    } else {
        ans = 0;
        //@ assert ans == 0;
        //@ assert !(((x) / 100) * 100 + 100 == (x));
    }
    
    //@ assert ans == 1 || ans == 0;
    //@ assert ans == 1 ==> (((x) / 100) * 100 + 100 == (x));
    //@ assert ans == 0 ==> !(((x) / 100) * 100 + 100 == (x));
    
    return ans;
}
