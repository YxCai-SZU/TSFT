#include <stdint.h>
/*@
    predicate in_range(integer n, integer m) =
        1 <= n && n <= 1000000000000000 &&
        1 <= m && m <= 1000000000000000;

    logic integer safe_n_times_2(integer n) = n * 2;
    logic integer safe_m_div_2(integer m) = m / 2;
    logic integer safe_expression(integer n, integer m) =
        n + (m - n * 2) / 4;

    lemma overflow_prevention:
        \forall integer n, m;
        in_range(n, m) ==>
        safe_n_times_2(n) <= 18446744073709551615 &&
        safe_m_div_2(m) <= 18446744073709551615 &&
        safe_expression(n, m) <= 18446744073709551615;
*/

/*@
    requires in_range(n, m);
    ensures \result <= n + m;
    ensures 0 <= \result;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    uint64_t result;
    uint64_t rem;

    //@ assert in_range(n, m);
    //@ assert safe_n_times_2(n) <= 18446744073709551615;
    //@ assert safe_m_div_2(m) <= 18446744073709551615;
    //@ assert safe_expression(n, m) <= 18446744073709551615;

    if (n * 2 > m)
    {
        result = m / 2;
        //@ assert result <= n + m;
        //@ assert 0 <= result;
        return result;
    }
    else
    {
        rem = m - n * 2;
        result = n + (rem / 4);
        //@ assert result <= n + m;
        //@ assert 0 <= result;
        return result;
    }
}
