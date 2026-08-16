#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 0 <= x <= 100;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top
    bool result;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);

    result = (a < b) && (b < c);
    return result;
}
