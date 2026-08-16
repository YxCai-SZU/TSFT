#include <stdbool.h>

/*@
    predicate intervals_overlap(integer a, integer b, integer c, integer d) =
        (a <= c && c <= b) ||
        (a <= d && d <= b) ||
        (c <= a && a <= d) ||
        (c <= b && b <= d);
 */

/*@
    requires a >= 1 && b <= 100;
    requires c >= 1 && d <= 100;
    requires b > a;
    requires d > c;
    ensures \result == true <==> intervals_overlap(a, b, c, d);
 */
bool func(int a, int b, int c, int d)
{
    // Variable declarations at the top
    bool result;

    if (a <= c && c <= b)
    {
        //@ assert a <= c && c <= b;
        return true;
    }
    if (a <= d && d <= b)
    {
        //@ assert a <= d && d <= b;
        return true;
    }
    if (c <= a && a <= d)
    {
        //@ assert c <= a && a <= d;
        return true;
    }
    if (c <= b && b <= d)
    {
        //@ assert c <= b && b <= d;
        return true;
    }
    return false;
}
