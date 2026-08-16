#include <stdint.h>

/*@
    predicate is_even(integer x) = x % 2 == 0;
    predicate is_odd(integer x) = x % 2 != 0;
*/

/*@
    requires 0 <= x <= 1000000000;
    ensures is_even(x) ==> \result == x / 2;
    ensures is_odd(x) ==> \result == 0;
*/
uint64_t func(uint64_t x)
{
    uint64_t ans;
    
    if (x % 2 == 0) {
        ans = x / 2;
        //@ assert ans == x / 2;
    } else {
        ans = 0;
        //@ assert ans == 0;
    }
    
    return ans;
}
