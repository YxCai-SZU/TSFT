#include <stdint.h>

/*@
    predicate is_valid_params(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= 100;

    logic integer compute_result(integer n, integer m) =
        n - m * 2;

    logic integer final_result(integer n, integer m) =
        compute_result(n, m) < 0 ? 0 : compute_result(n, m);
*/

/*@
    requires is_valid_params(n, m);
    ensures \result >= 0;
    ensures \result == compute_result(n, m) || \result == 0;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t m)
{
    // Variable declarations at scope top
    int64_t ans;

    //@ assert n >= 1 && n <= 100;
    //@ assert m >= 1 && m <= 100;
    //@ assert m * 2 <= 200;

    ans = n - m * 2;
    if (ans < 0) {
        ans = 0;
    }
    return ans;
}
