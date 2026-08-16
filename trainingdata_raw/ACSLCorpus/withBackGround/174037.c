#include <stdint.h>

/*@
    predicate valid_range(integer a, integer p) =
        0 <= a && a <= 100 &&
        0 <= p && p <= 100;

    logic integer max_pies(integer a, integer p) = (a * 3 + p) / 2;

    lemma pies_bound: \forall integer a, p;
        valid_range(a, p) ==> max_pies(a, p) <= a * 3 + p;
*/

/*@
    requires valid_range(a, p);
    ensures \result <= a * 3 + p;
    ensures \result == max_pies(a, p);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t p)
{
    //@ assert a * 3 + p <= 100 * 3 + 100;
    return (a * 3 + p) / 2;
}
