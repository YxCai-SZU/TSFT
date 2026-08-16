#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    predicate condition(integer a, integer b, integer c, integer d) =
        (c <= b && a <= d) || (c <= d && a <= b);
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == true <==> condition(a, b, c, d);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    
    if ((c <= b && a <= d) || (c <= d && a <= b)) {
        //@ assert condition(a, b, c, d);
        result = true;
    } else {
        //@ assert !condition(a, b, c, d);
        result = false;
    }
    
    return result;
}
