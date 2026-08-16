#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 100;
    predicate b_in_range(integer b) = 1 <= b && b <= 100;
    logic integer product(integer a, integer b) = a * b;
*/

/*@
    lemma lemma_a_in_range: \forall integer a; a_in_range(a) ==> a <= 100;
    lemma lemma_b_in_range: \forall integer b; b_in_range(b) ==> b <= 100;
*/

/*@
    requires a_in_range(a);
    requires b_in_range(b);
    ensures \result == product(a, b);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert product(a, b) <= 10000;
    return a * b;
}
