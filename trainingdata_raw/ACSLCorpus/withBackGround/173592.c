#include <stdbool.h>

/*@
    predicate condition(integer a, integer b, integer c) =
        (a == b && b != c) || (a != b && a == c) || (a != b && b == c);
*/

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == true <==> condition(a, b, c);
*/
bool func(int a, int b, int c)
{
    bool ans;
    ans = false;

    if (a == b && b != c)
    {
        ans = true;
    }
    else if (a != b && a == c)
    {
        ans = true;
    }
    else if (a != b && b == c)
    {
        ans = true;
    }

    //@ assert ans == true <==> condition(a, b, c);
    return ans;
}
