#include <stdbool.h>

/*@
    predicate valid_input(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer compute_result(integer a, integer b) =
        a - 2 * b;

    predicate result_valid(integer res, integer a, integer b) =
        res >= 0 && (res == compute_result(a, b) || res == 0);
*/

/*@
    requires valid_input(a, b);
    ensures result_valid(\result, a, b);
    assigns \nothing;
*/
int func(int a, int b)
{
    int ans;
    int res;

    ans = a - 2 * b;

    if (ans > 0)
    {
        //@ assert ans > 0;
        res = ans;
    }
    else
    {
        //@ assert ans <= 0;
        res = 0;
    }

    //@ assert res >= 0 && (res == ans || res == 0);
    return res;
}
