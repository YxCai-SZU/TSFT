#include <stdint.h>

/*@
    predicate valid_inputs(integer n, integer m) =
        1 <= n && 1 <= m && n <= 1000000000000 && m <= 1000000000000;

    logic integer formula1(integer m) = m / 2;
    logic integer formula2(integer n, integer m) = n + (m - 2 * n) / 4;

    lemma answer_bounds_case1:
        \forall integer n, m, answer;
        valid_inputs(n, m) && n > m / 2 && answer == m / 2 ==>
        answer <= m / 2 && answer <= n + (m - 2 * n) / 4;

    lemma answer_bounds_case2:
        \forall integer n, m, answer;
        valid_inputs(n, m) && n <= m / 2 && answer == n + (m - 2 * n) / 4 ==>
        answer <= m / 2 && answer <= n + (m - 2 * n) / 4;
*/

/*@
    requires valid_inputs(n, m);
    ensures \result <= m / 2;
    ensures \result <= n + (m - 2 * n) / 4;
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t m)
{
    uint32_t answer;

    if (n > m / 2)
    {
        answer = m / 2;
        //@ assert answer == m / 2;
        //@ assert answer <= m / 2;
        //@ assert answer <= n + (m - 2 * n) / 4;
    }
    else
    {
        answer = n + (m - 2 * n) / 4;
        //@ assert answer == n + (m - 2 * n) / 4;
        //@ assert answer <= m / 2;
        //@ assert answer <= n + (m - 2 * n) / 4;
    }

    return answer;
}
