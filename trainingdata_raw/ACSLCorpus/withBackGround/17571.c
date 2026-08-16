#include <stdbool.h>

/*@
    predicate condition_holds(integer a, integer b, integer c, integer d) =
        (c - b <= 0) ||
        (b - a <= 0) ||
        (a - c <= 0) ||
        (b - d <= 0) ||
        (c - a <= 0) ||
        (d - b <= 0);
*/

/*@
    requires 0 <= a <= 10000;
    requires 0 <= b <= 10000;
    requires 0 <= c <= 10000;
    requires 0 <= d <= 10000;
    ensures \result == 1 <==> condition_holds(a, b, c, d);
*/
bool func(int a, int b, int c, int d)
{
    bool flag = false;

    //@ assert flag == false;

    if (c - b <= 0)
    {
        flag = true;
    }

    if (b - a <= 0)
    {
        flag = true;
    }

    if (a - c <= 0)
    {
        flag = true;
    }

    if (b - d <= 0)
    {
        flag = true;
    }

    if (c - a <= 0)
    {
        flag = true;
    }

    if (d - b <= 0)
    {
        flag = true;
    }

    //@ assert flag == 1 <==> condition_holds(a, b, c, d);

    return flag;
}
