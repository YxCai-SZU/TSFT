#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= k && k <= n && n <= 50;

    logic integer compute_result(integer n, integer k) =
        n - k + 1;
*/

/*@
    requires valid_params(n, k);
    ensures \result == compute_result(n, k);
    assigns \nothing;
*/
int func(int n, int k) {
    int r;
    
    //@ assert valid_params(n, k);
    r = n - k + 1;
    //@ assert r == compute_result(n, k);
    return r;
}
