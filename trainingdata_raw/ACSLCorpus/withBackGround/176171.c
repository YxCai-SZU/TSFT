#include <stdint.h>

/*@ predicate valid_range(integer v) = 1 <= v <= 205; */

/*@
    requires valid_range(x) && valid_range(y);
    ensures \result >= 0 && \result <= 1000000;
    assigns \nothing;
*/
int32_t func(uint16_t x, uint16_t y)
{
    int32_t ans = 0;

    if (x == 1)
    {
        if (y == 1)
        {
            ans = 1000000;
        }
        else if (y == 2)
        {
            ans = 500000;
        }
        else
        {
            ans = 0;
        }
    }
    else if (x == 2)
    {
        if (y == 1)
        {
            ans = 500000;
        }
        else if (y == 2)
        {
            ans = 0;
        }
        else
        {
            ans = 0;
        }
    }

    //@ assert ans >= 0;
    //@ assert ans <= 1000000;
    return ans;
}

/*@ lemma func_postconditions: 
        \forall integer x, y, ans; 
        valid_range(x) && valid_range(y) && ans >= 0 && ans <= 1000000 ==> 
        ans >= 0 && ans <= 1000000;
*/
