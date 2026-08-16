#include <stdint.h>

/*@
    requires (1 <= (x) <= 1000000000 &&
        1 <= (t) <= 1000000000);
    ensures \result >= 0;
    ensures x > t ==> \result == x - t;
    ensures x <= t ==> \result == 0;
    assigns \nothing;
*/
int64_t func(int64_t x, int64_t t)
{
    int64_t result;
    //@ assert (1 <= (x) <= 1000000000 &&         1 <= (t) <= 1000000000);
    
    if (x > t)
    {
        //@ assert x - t >= 0;
        result = x - t;
    }
    else
    {
        //@ assert 0 >= 0;
        result = 0;
    }
    
    //@ assert result >= 0;
    return result;
}
