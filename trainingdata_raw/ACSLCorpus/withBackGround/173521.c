#include <stdbool.h>

/*@
    predicate can_communicate_cond(integer a, integer b, integer c, integer d) =
        b >= c && a <= d;
 */

/*@
    requires -1000000000 <= a <= b <= 1000000000;
    requires -1000000000 <= c <= d <= 1000000000;
    ensures \result == true <==> can_communicate_cond(a, b, c, d);
    assigns \nothing;
 */
bool can_communicate(int a, int b, int c, int d)
{
    bool result;

    //@ assert -1000000000 <= a && a <= b && b <= 1000000000;
    //@ assert -1000000000 <= c && c <= d && d <= 1000000000;

    if (b < c || a > d)
    {
        result = false;
        //@ assert !can_communicate_cond(a, b, c, d);
    }
    else
    {
        //@ assert can_communicate_cond(a, b, c, d);
        result = true;
    }

    return result;
}
