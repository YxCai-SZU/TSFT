#include <stdint.h>

/*@
    predicate valid_inputs(integer a, integer p) =
        0 <= a <= 100 && 0 <= p <= 100;

    logic integer total_pieces(integer a, integer p) = a * 3 + p;

    lemma result_bound: \forall integer a, p, r;
        valid_inputs(a, p) && r == total_pieces(a, p) / 2 ==> r <= p + a * 3;
*/

/*@
    requires valid_inputs(a, p);
    ensures \result <= p + a * 3;
    ensures \result == (a * 3 + p) / 2;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t p)
{
    uint32_t total_pieces;
    uint32_t result;

    //@ assert valid_inputs(a, p);
    
    total_pieces = a * 3 + p;
    //@ assert total_pieces == a * 3 + p;
    
    result = total_pieces / 2;
    //@ assert result == (a * 3 + p) / 2;
    
    //@ assert result <= p + a * 3;
    
    return result;
}
