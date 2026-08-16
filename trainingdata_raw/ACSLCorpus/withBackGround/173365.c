#include <stdint.h>

/*@
    predicate is_valid_params(integer n, integer m) =
        1 <= n && 1 <= m && n <= 1000000000000 && m <= 1000000000000;

    logic integer func_spec(integer n, integer m) =
        n * 2 > m ? m / 2 : n + ((m - n * 2) / 4);

    lemma func_bounds: \forall integer n, m;
        is_valid_params(n, m) ==> 0 <= func_spec(n, m) && func_spec(n, m) <= n + m / 2;
*/

/*@
    requires is_valid_params(n, m);
    ensures \result >= 0;
    ensures \result <= n + m / 2;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    uint64_t result;
    uint64_t rem;

    //@ assert n * 2 > m ==> m / 2 >= 0;
    if (n * 2 > m) {
        result = m / 2;
        //@ assert result >= 0;
        //@ assert result <= n + m / 2;
        return result;
    }

    rem = m - n * 2;
    //@ assert rem <= m;
    result = n + (rem / 4);
    //@ assert result >= 0;
    //@ assert result <= n + m / 2;
    return result;
}
