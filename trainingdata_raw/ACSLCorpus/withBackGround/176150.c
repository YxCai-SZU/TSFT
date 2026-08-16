#include <stdbool.h>

/*@
    predicate condition_holds(integer a, integer b, integer c, integer d) =
        (a < c && c < b && b <= d) ||
        (a <= c && b <= d && b > c) ||
        (a <= c && d <= b);
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    requires a < b;
    requires c < d;
    ensures \result == true <==> condition_holds(a, b, c, d);
*/
bool func(int a, int b, int c, int d)
{
    bool res = false;

    //@ assert a < b && c < d;

    if (a < c && c < b && b <= d) {
        res = true;
    } else if (a <= c && b <= d && b > c) {
        res = true;
    } else if (a <= c && d <= b) {
        res = true;
    }

    //@ assert res == true <==> condition_holds(a, b, c, d);

    return res;
}
