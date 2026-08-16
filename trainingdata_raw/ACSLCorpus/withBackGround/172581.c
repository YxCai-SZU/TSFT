#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100 &&
        a * b <= 9223372036854775807 && a * b >= -9223372036854775808;
*/

/*@
    requires valid_range(a, b);
    ensures \result == a * b;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    // Variable declarations at top of scope
    int64_t ans;

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert a * b <= 9223372036854775807;
    //@ assert a * b >= -9223372036854775808;
    
    ans = a * b;
    //@ assert ans == a * b;
    
    return ans;
}
