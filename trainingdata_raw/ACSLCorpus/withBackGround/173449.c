#include <stdbool.h>

/*@
    predicate is_valid_triangle(integer a, integer b, integer c) =
        0 <= a <= 100 && 0 <= b <= 100 && 0 <= c <= 100 &&
        a + b + c == 180;
*/

/*@
    requires is_valid_triangle(a, b, c);
    ensures \result == (a > 0 && b > 0 && c > 0 && a < 180 && b < 180 && c < 180);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert a + b + c == 180;
    
    if (a > 0 && b > 0 && c > 0 && a < 180 && b < 180 && c < 180)
    {
        return true;
    }
    else
    {
        return false;
    }
}
