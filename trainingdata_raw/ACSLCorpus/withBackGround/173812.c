#include <stdint.h>

/*@
    predicate in_range(integer x) = 0 <= x <= 1000000000;

    logic integer compute_result(integer x) =
        (x / 500) * 1000 + ((x % 500) / 5) * 5;

    lemma division_property:
        \forall integer x, d; 0 <= x && 0 < d ==> x / d * d <= x < (x / d + 1) * d;
*/

/*@
    requires in_range(x);
    ensures \result == compute_result(x);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t n1;
    uint32_t n2;
    uint32_t n3;
    uint32_t res;

    n1 = x / 500;
    n2 = x - 500 * n1;
    n3 = n2 / 5;
    res = n1 * 1000 + n3 * 5;

    //@ assert n1 == x / 500;
    //@ assert n2 == x - 500 * n1;
    //@ assert n3 == n2 / 5;
    //@ assert res == n1 * 1000 + n3 * 5;
    //@ assert res == compute_result(x);

    return res;
}
