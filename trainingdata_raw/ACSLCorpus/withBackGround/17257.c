#include <stdint.h>

/*@
    predicate valid_inputs(integer n, integer m) =
        1 <= n <= 1000000000000 &&
        1 <= m <= 1000000000000;

    logic integer half_m(integer m) =
        m >= 2 ? m / 2 : 0;

    logic integer quarter_m(integer m) =
        m >= 4 ? m / 4 : 0;

    lemma res_upper_bound:
        \forall integer n, m, res, half_m, quarter_m;
        valid_inputs(n, m) &&
        half_m == (m >= 2 ? m / 2 : 0) &&
        quarter_m == (m >= 4 ? m / 4 : 0) &&
        (
            (n >= half_m && res == half_m + quarter_m && m == m - 2 * half_m) ||
            (n < half_m && res == n + quarter_m && m == m - 2 * n)
        ) ==>
        res <= n + m / 2;

    lemma res_lower_bound:
        \forall integer n, m, res, half_m, quarter_m;
        valid_inputs(n, m) &&
        half_m == (m >= 2 ? m / 2 : 0) &&
        quarter_m == (m >= 4 ? m / 4 : 0) &&
        (
            (n >= half_m && res == half_m + quarter_m && m == m - 2 * half_m) ||
            (n < half_m && res == n + quarter_m && m == m - 2 * n)
        ) ==>
        res >= m / 4;
*/

/*@
    requires valid_inputs(n, m);
    ensures \result <= n + m / 2;
    ensures \result >= m / 4;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    uint64_t res = 0;
    uint64_t half_m;
    uint64_t quarter_m;
    uint64_t original_n = n;
    uint64_t original_m = m;

    //@ assert valid_inputs(n, m);

    // Implement division by 2 manually
    if (m >= 2)
    {
        half_m = m / 2;
    }
    else
    {
        half_m = 0;
    }

    //@ assert half_m == (original_m >= 2 ? original_m / 2 : 0);

    if (n >= half_m)
    {
        res += half_m;
        m -= 2 * half_m;
        //@ assert res == half_m;
    }
    else
    {
        res += n;
        m -= 2 * n;
        //@ assert res == n;
    }

    // Implement division by 4 manually
    if (m >= 4)
    {
        quarter_m = m / 4;
    }
    else
    {
        quarter_m = 0;
    }

    //@ assert quarter_m == (m >= 4 ? m / 4 : 0);

    res += quarter_m;

    //@ assert res <= original_n + original_m / 2;
    //@ assert res >= m / 4;

    return res;
}
