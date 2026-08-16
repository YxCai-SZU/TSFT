#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;

    logic integer calc_x(integer n) = n * 800;
    logic integer calc_y(integer n) = (n / 15) * 200;
    logic integer calc_res(integer n) = calc_x(n) - calc_y(n);

    lemma x_bounds: \forall integer n; valid_n(n) ==> 800 <= calc_x(n) && calc_x(n) <= 80000;
    lemma y_bounds: \forall integer n; valid_n(n) ==> 0 <= calc_y(n) && calc_y(n) <= 1200;
    lemma res_bounds: \forall integer n; valid_n(n) ==> 600 <= calc_res(n) && calc_res(n) <= 80000;
*/

/*@
    requires valid_n(n);
    ensures \result == calc_res(n);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    // Variable declarations at top
    uint32_t x;
    uint32_t y;
    int32_t result;

    //@ assert valid_n(n);

    // Calculate x = n * 800
    //@ assert 800 <= n * 800 && n * 800 <= 80000;
    x = n * 800;

    // Calculate y = (n / 15) * 200
    //@ assert 0 <= n / 15 && n / 15 <= 6;
    y = (n / 15) * 200;

    // Final calculation
    //@ assert 600 <= n * 800 - (n / 15) * 200 && n * 800 - (n / 15) * 200 <= 80000;
    result = (int32_t)x - (int32_t)y;

    //@ assert result == calc_res(n);
    return result;
}
