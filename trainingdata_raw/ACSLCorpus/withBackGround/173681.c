#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a && a <= 16 &&
        1 <= b && b <= 16 &&
        a + b <= 16;
*/

/*@
    requires valid_range(a, b);
    ensures \result == (a <= 8 && b <= 8);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert a + b <= 16;
    
    result = (a <= 8 && b <= 8);
    return result;
}
