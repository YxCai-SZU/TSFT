#include <stdint.h>

/*@
    requires -1000 <= x <= 1000;
    ensures (x >= 0 ==> \result == x) && (x < 0 ==> \result == 0);
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    int64_t result;
    //@ ghost int64_t original_x = x;
    
    if (x > 0)
    {
        //@ assert x > 0;
        result = x;
    }
    else
    {
        //@ assert x <= 0;
        result = 0;
    }
    
    return result;
}
