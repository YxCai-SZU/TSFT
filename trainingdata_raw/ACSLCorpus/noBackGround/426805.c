#include <stdint.h>

/*@
    requires -10 <= x && x <= 10;
    ensures \result == (x >= 0 ? 1 : 0);
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    int64_t ans;
    //@ assert -10 <= x && x <= 10;
    
    if (x >= 0)
    {
        ans = 1;
        //@ assert ans == 1;
    }
    else
    {
        ans = 0;
        //@ assert ans == 0;
    }
    
    //@ assert (x >= 0 ==> ans == 1) && (x < 0 ==> ans == 0);
    return ans;
}
