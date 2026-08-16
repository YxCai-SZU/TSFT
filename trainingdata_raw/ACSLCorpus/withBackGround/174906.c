#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == (a - c <= d && d - a - c <= b);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);
    
    bool result;
    result = (a - c <= d) && (d - a - c <= b);
    return result;
}
