#include <stdint.h>

/*@
    predicate is_nat(integer x) = x >= 0;

    logic integer multiply(integer a, integer b) = a * b;

    lemma multiplication_bound:
        \forall integer a, b;
            is_nat(a) && is_nat(b) && a <= 10000 && b <= 10000 ==>
            multiply(a, b) <= 100000000;
*/

/*@
    requires is_nat(a) && is_nat(b);
    requires a <= 10000 && b <= 10000;
    ensures \result == multiply(a, b);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    //@ assert a <= 10000 && b <= 10000;
    return a * b;
}
