#include <stdint.h>

/*@
    predicate valid_input(integer n, integer m) =
        1 <= n && n <= 1000000000000 &&
        1 <= m && m <= 1000000000000;

    logic integer func_result(integer n, integer m) =
        n * 2 <= m ? n + (m - n * 2) / 4 : m / 2;

    lemma result_bounds:
        \forall integer n, m;
        valid_input(n, m) ==>
        0 <= func_result(n, m) && func_result(n, m) <= n + m;
*/

/*@
    requires valid_input(n, m);
    ensures \result >= 0;
    ensures \result <= n + m;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    uint64_t result;

    //@ assert valid_input(n, m);

    if (n * 2 <= m)
    {
        //@ assert n * 2 <= m;
        //@ assert n + (m - n * 2) / 4 >= 0;
        result = n + (m - n * 2) / 4;
    }
    else
    {
        //@ assert m / 2 <= n;
        //@ assert m / 2 >= 0;
        result = m / 2;
    }

    //@ assert result >= 0;
    //@ assert result <= n + m;
    return result;
}
