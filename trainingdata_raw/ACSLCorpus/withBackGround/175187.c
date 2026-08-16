#include <stdint.h>

/*@
    predicate valid_inputs(integer a, integer p) =
        0 <= a && a <= 100 &&
        0 <= p && p <= 100;

    logic integer compute_pies(integer a, integer p) =
        (a * 3 + p) / 2;

    lemma arithmetic_identity:
        \forall integer a, p, x;
        valid_inputs(a, p) && x == a * 3 + p ==>
        x / 2 == compute_pies(a, p);
*/

/*@
    requires valid_inputs(a, p);
    ensures \result == compute_pies(a, p);
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t p)
{
    uint64_t x;
    uint64_t pies;

    x = a * 3 + p;
    
    //@ assert x / 2 == compute_pies(a, p);
    
    pies = x / 2;
    return pies;
}
