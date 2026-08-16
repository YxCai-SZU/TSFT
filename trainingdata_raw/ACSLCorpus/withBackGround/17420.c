#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;
    predicate loop_inv(integer n, integer v, integer res) =
        1 <= n && n <= 100 &&
        1 <= v &&
        res <= n &&
        res >= 1;
    logic integer decreases_term(integer n, integer v) = n - v / 2;
*/

/*@
    requires is_valid_n(n);
    ensures \result <= n;
    ensures \result >= 1;
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    uint32_t res;
    uint32_t v;

    //@ assert is_valid_n(n);
    res = 1;
    v = 1;

    /*@
        loop invariant loop_inv(n, v, res);
        loop assigns v, res;
        loop variant decreases_term(n, v);
    */
    while (v <= n)
    {
        //@ assert v <= n;
        if (v <= n)
        {
            res = v;
        }
        v += 2;
    }

    //@ assert res <= n;
    //@ assert res >= 1;
    return res;
}
