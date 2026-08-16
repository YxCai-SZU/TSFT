#include <stdbool.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer bound(integer a, integer b, integer c) =
        a - b + c;
*/

/*@
    requires valid_input(a, b, c);
    ensures \result >= 0;
    ensures \result <= bound(a, b, c);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans;
    ans = c - a + b;

    //@ assert ans == c - a + b;
    if (ans < 0)
    {
        ans = 0;
    }

    //@ assert ans >= 0;
    //@ assert ans <= bound(a, b, c);
    return ans;
}
