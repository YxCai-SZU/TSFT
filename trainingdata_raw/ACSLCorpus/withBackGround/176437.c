#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b, integer c, integer d) =
        0 <= a <= 100 && 0 <= b <= 100 && 0 <= c <= 100 && 0 <= d <= 100 &&
        a <= b && c <= d;
        
    predicate intervals_overlap(integer a, integer b, integer c, integer d) =
        b >= c && a <= d;
*/

/*@
    requires valid_range(a, b, c, d);
    ensures \result == 1 <==> intervals_overlap(a, b, c, d);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    //@ assert valid_range(a, b, c, d);
    
    bool result = (b >= c) && (a <= d);
    
    //@ assert result == 1 <==> intervals_overlap(a, b, c, d);
    return result;
}
