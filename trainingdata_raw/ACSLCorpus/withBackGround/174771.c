#include <stdbool.h>

/*@
    predicate is_valid_params(integer n, integer r) =
        1 <= n <= 100 && 0 <= r <= 4111;

    logic integer compute_result(integer n, integer r) =
        n >= 10 ? r : r + 100 * (10 - n);
*/

/*@
    requires is_valid_params(n, r);
    ensures \result == compute_result(n, r);
    assigns \nothing;
*/
int func(int n, int r)
{
    int ans;
    
    if (n >= 10) {
        ans = r;
        //@ assert ans == r;
    } else {
        ans = r + 100 * (10 - n);
        //@ assert ans == r + 100 * (10 - n);
    }
    
    return ans;
}
