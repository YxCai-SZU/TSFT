#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;

    logic integer compute_x(integer n) = 800 * n;
    logic integer compute_y(integer n) = n / 15;
    logic integer compute_z(integer n) = 200 * compute_y(n);
    logic integer compute_result(integer n) = compute_x(n) - compute_z(n);

    lemma result_correctness:
        \forall integer n; valid_n(n) ==> compute_result(n) == 800 * n - 200 * (n / 15);
*/

/*@
    requires valid_n(n);
    ensures \result == 800 * n - 200 * (n / 15);
    assigns \nothing;
*/
int32_t func(uint64_t n)
{
    int32_t x;
    uint64_t y;
    int32_t z;
    int32_t ans;

    //@ assert valid_n(n);
    x = 800 * (int32_t)n;
    //@ assert x == compute_x(n);
    y = n / 15;
    //@ assert y == compute_y(n);
    z = 200 * (int32_t)y;
    //@ assert z == compute_z(n);
    ans = x - z;
    //@ assert ans == compute_result(n);
    return ans;
}
