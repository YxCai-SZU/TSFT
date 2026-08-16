#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    predicate c_in_range(integer c) = 1 <= c <= 100;
    predicate d_in_range(integer d) = 1 <= d <= 100;
    
    predicate condition_holds(integer a, integer b, integer c, integer d) =
        (a - d >= 1 && a - c >= 1) ||
        (b - d >= 1 && b - c >= 1) ||
        (c - b >= 1 && c - a >= 1) ||
        (d - b >= 1 && d - a >= 1);
*/

/*@
    requires a_in_range(a) && b_in_range(b) && c_in_range(c) && d_in_range(d);
    ensures \result == true <==> condition_holds(a, b, c, d);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert c_in_range(c);
    //@ assert d_in_range(d);
    
    return (a - d >= 1 && a - c >= 1) ||
           (b - d >= 1 && b - c >= 1) ||
           (c - b >= 1 && c - a >= 1) ||
           (d - b >= 1 && d - a >= 1);
}
