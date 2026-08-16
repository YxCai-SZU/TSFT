#include <stddef.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 1000;

    logic integer max_division(integer a, integer b, integer c, integer d) =
        (b / c > a / d) ? (b / c) : (a / d);
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(c);
    requires valid_range(d);
    ensures \result == max_division(a, b, c, d);
*/
size_t func(size_t a, size_t b, size_t c, size_t d)
{
    size_t max_val;

    //@ assert c > 0 && d > 0;
    
    if (b / c > a / d)
    {
        max_val = b / c;
    }
    else
    {
        max_val = a / d;
    }

    //@ assert max_val == max_division(a, b, c, d);
    
    return max_val;
}
