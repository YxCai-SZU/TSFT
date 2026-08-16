#include <limits.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        0 <= a && a <= 100 &&
        0 <= b && b <= 100 &&
        0 <= c && c <= 100 &&
        1 <= k && k <= 3;

    logic integer expected_result(integer a, integer b, integer c, integer k) =
        k == 1 ? a :
        k == 2 ? a + b :
        k == 3 ? a + b + c :
        -1;
*/

/*@
    requires valid_params(a, b, c, k);
    ensures \result == expected_result(a, b, c, k);
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int ans;

    if (k == 1)
    {
        ans = a;
        //@ assert ans == a;
    }
    else if (k == 2)
    {
        ans = a + b;
        //@ assert ans == a + b;
    }
    else if (k == 3)
    {
        ans = a + b + c;
        //@ assert ans == a + b + c;
    }
    else
    {
        ans = -1;
        //@ assert ans == -1;
    }

    return ans;
}
