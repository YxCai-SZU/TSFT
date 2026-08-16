#include <stdbool.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= 100;

    logic integer compute_result(integer n, integer m) =
        n - 2 * m;

    predicate result_nonnegative(integer r) =
        r >= 0;

    predicate result_correct(integer r, integer n, integer m) =
        r == compute_result(n, m) || r == 0;
*/

/*@
    requires valid_range(n, m);
    ensures result_nonnegative(\result);
    ensures result_correct(\result, n, m);
*/
int func(int n, int m)
{
    int result;

    result = n - 2 * m;
    
    if (result > 0)
    {
        //@ assert result == n - 2 * m;
        return result;
    }
    else
    {
        return 0;
    }
}
