#include <stdint.h>
/*@
    predicate valid_x(integer x) = 1 <= x && x <= 1000000000000000;
    logic integer upper_bound(integer x) = 2 * (x / 11) + 2;
    logic integer lower_bound(integer x) = 0;
*/

/*@
    requires valid_x(x);
    ensures \result <= upper_bound(x);
    ensures \result >= lower_bound(x);
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t ans;
    //@ assert valid_x(x);
    ans = (x / 11) * 2;
    //@ assert ans == 2 * (x / 11);
    
    if (x % 11 > 6) {
        ans += 2;
    } else {
        ans += 1;
    }
    //@ assert ans <= upper_bound(x);
    return ans;
}
