#include <stdbool.h>

/*@
    predicate is_overlap(integer a, integer b, integer c, integer d) =
        a > d || b > c || (a <= c && c <= b) || (c <= a && a <= d);
 */

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    requires a <= b;
    requires c <= d;
    ensures \result == true <==> is_overlap(a, b, c, d);
    assigns \nothing;
 */
bool func(int a, int b, int c, int d)
{
    bool x = false;

    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 && 1 <= d <= 100;
    //@ assert a <= b && c <= d;

    if (a > d)
    {
        x = true;
    }

    if (b > c)
    {
        x = true;
    }

    if (a <= c && c <= b)
    {
        x = true;
    }

    if (c <= a && a <= d)
    {
        x = true;
    }

    //@ assert x == true <==> is_overlap(a, b, c, d);
    return x;
}
