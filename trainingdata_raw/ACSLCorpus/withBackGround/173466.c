#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer r) =
        1 <= n && n <= 100 &&
        0 <= r && r <= 4111;

    logic integer compute_result(integer n, integer r) =
        n >= 10 ? r : r + 100 * (10 - n);
*/

/*@
    requires valid_params(n, r);
    ensures \result == compute_result(n, r);
    ensures n >= 10 ==> \result == r;
    ensures n < 10 ==> \result == r + 100 * (10 - n);
*/
int func(int n, int r)
{
    int ans;
    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= r && r <= 4111;
    
    if (n >= 10)
    {
        ans = r;
    }
    else
    {
        //@ assert 0 <= 100 * (10 - n) && 100 * (10 - n) <= 100 * 10;
        //@ assert r <= 4111;
        //@ assert r + 100 * (10 - n) <= 4111 + 100 * 10;
        ans = r + 100 * (10 - n);
    }
    
    return ans;
}
