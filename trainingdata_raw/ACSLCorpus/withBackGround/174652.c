#include <stdint.h>

/*@
    predicate is_three_digit(integer n) =
        100 <= n && n <= 999;

    logic integer compute_result(integer n) =
        111 * (n / 111) + 111;
*/

/*@
    requires is_three_digit(n);
    assigns \nothing;
    ensures \result == compute_result(n);
*/
uint64_t func(uint64_t n)
{
    uint64_t n_div_111;
    uint64_t ans;

    n_div_111 = n / 111;
    ans = 111 * n_div_111 + 111;

    //@ assert ans == 111 * (n / 111) + 111;

    return ans;
}
