/*@
    predicate bounds(integer a, integer b) =
        1 <= a && a <= 5 && 1 <= b && b <= 5;

    logic integer mul_bounded(integer a, integer b) = a * b;

    lemma mul_upper_bound:
        \forall integer a, integer b;
            bounds(a, b) ==> mul_bounded(a, b) <= 25;
*/

#include <stdint.h>

/*@
    requires bounds(a, b);
    ensures \result == mul_bounded(a, b);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    //@ assert bounds(a, b);
    //@ assert mul_bounded(a, b) <= 25;
    return a * b;
}
