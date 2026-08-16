#include <stdint.h>

/*@
    predicate is_valid_x(integer x) = 1 <= x <= 100000;

    logic integer mod_100(integer x) = x % 100;
    logic integer calc_i(integer n) = (n * 21) / 100;

    lemma mod_calc_prop:
        \forall integer x, n, i;
            is_valid_x(x) ==>
            n == mod_100(x) ==>
            i == calc_i(n) ==>
            (i == n ==> (mod_100(x) * 21) / 100 == mod_100(x)) &&
            (i != n ==> (mod_100(x) * 21) / 100 != mod_100(x));
*/

/*@
    requires is_valid_x(x);
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> (x % 100) * 21 / 100 == x % 100;
    ensures \result == 0 ==> (x % 100) * 21 / 100 != x % 100;
*/
int32_t func(uint32_t x)
{
    uint32_t n;
    uint32_t i;
    int32_t result;

    n = x % 100;
    i = (n * 21) / 100;

    if (i == n)
    {
        result = 1;
        //@ assert (x % 100) * 21 / 100 == x % 100;
    }
    else
    {
        //@ assert (x % 100) * 21 / 100 != x % 100;
        result = 0;
    }

    return result;
}
