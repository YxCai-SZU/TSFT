#include <stdint.h>

/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= 100;

    logic integer compute_result(integer n, integer m) =
        n > 13 ? m * 2 : m;

    lemma m_double_bounded: \forall integer m; 1 <= m <= 100 ==> m * 2 <= 200;
*/

/*@
    requires valid_params(n, m);
    ensures \result == compute_result(n, m);
    ensures n > 13 ==> \result == m * 2;
    ensures n <= 13 ==> \result == m;
*/
int32_t func(uint32_t n, uint32_t m)
{
    uint32_t ans;
    uint32_t i;

    //@ assert valid_params(n, m);

    if (n > 13)
    {
        //@ assert m * 2 <= 200;
        ans = m * 2;
    }
    else
    {
        ans = m;
    }

    i = 0;
    /*@
        loop invariant 0 <= i <= n;
        loop invariant valid_params(n, m);
        loop assigns i;
    */
    while (i < n)
    {
        i = i + 1;
    }

    if (n > 13)
    {
        //@ assert ans == m * 2;
    }
    else
    {
        //@ assert ans == m;
    }

    return (int32_t)ans;
}
