#include <stdint.h>

/*@
    predicate is_even(integer x) = x % 2 == 0;
    predicate is_odd(integer x) = x % 2 != 0;
*/

/*@
    requires 0 <= x <= 1000000000;
    ensures is_even(x) ==> \result == x;
    ensures is_odd(x) ==> \result == 2 * x;
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t ans;
    
    if (x % 2 == 0)
    {
        ans = x;
        //@ assert ans == x;
    }
    else
    {
        ans = 2 * x;
        //@ assert ans == 2 * x;
    }
    
    return ans;
}
