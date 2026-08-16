#include <stdint.h>

/*@
    predicate valid_month(integer m) = 1 <= m && m <= 12;

    predicate check_in_before_check_out(integer m1, integer d1, integer m2, integer d2) =
        m1 < m2 || (m1 == m2 && d1 < d2);

    logic integer is_consecutive(integer m1, integer m2) =
        m2 - m1 == 1 ? 1 : 0;
 */

/*@
    requires valid_month(m1) && valid_month(m2);
    requires check_in_before_check_out(m1, d1, m2, d2);
    ensures \result == is_consecutive(m1, m2);
 */
uint64_t func(uint64_t m1, uint64_t d1, uint64_t m2, uint64_t d2)
{
    uint64_t ans;

    //@ assert valid_month(m1) && valid_month(m2);
    //@ assert check_in_before_check_out(m1, d1, m2, d2);

    if (m2 - m1 == 1)
    {
        ans = 1;
        //@ assert ans == 1;
    }
    else
    {
        ans = 0;
        //@ assert ans == 0;
    }

    //@ assert ans == is_consecutive(m1, m2);
    return ans;
}
