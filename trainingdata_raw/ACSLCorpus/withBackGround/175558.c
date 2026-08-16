#include <stdint.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= 100;

    logic integer func_result(integer n, integer m) =
        n + m / 2;

    lemma result_bounds: \forall integer n, m;
        valid_range(n, m) ==> 1 <= func_result(n, m) <= 150;
*/

/*@
    requires valid_range(n, m);
    ensures \result == func_result(n, m);
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t m)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert n <= 100;
    //@ assert m <= 200;
    //@ assert m / 2 <= 50;
    //@ assert n + m / 2 <= 150;
    //@ assert n + m / 2 <= 100 + 50;
    //@ assert n + m / 2 >= 1;

    result = n + m / 2;
    return result;
}
