#include <stdbool.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= 100;

    logic integer compute_result(integer n, integer m) =
        n - 2 * m;

    predicate result_nonnegative(integer res) =
        res >= 0;

    predicate result_correct(integer res, integer n, integer m) =
        res == n - 2 * m || res == 0;
*/

/*@
    requires valid_range(n, m);
    ensures result_nonnegative(\result);
    ensures result_correct(\result, n, m);
*/
int func(int n, int m)
{
    int res;
    
    //@ assert valid_range(n, m);
    
    res = n - 2 * m;
    
    if (res > 0)
    {
        //@ assert res >= 0;
        return res;
    }
    else
    {
        //@ assert 0 >= 0;
        return 0;
    }
}
