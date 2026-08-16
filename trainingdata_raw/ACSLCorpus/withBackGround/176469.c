#include <stdint.h>

/*@
    predicate bounds(integer v) = 0 <= v <= 0xffffffff;

    logic integer xor_op(integer x, integer y) = x ^ y;

    lemma xor_bitwidth:
        \forall integer x, integer y;
            bounds(x) && bounds(y) ==>
            xor_op(x, y) == (x ^ y);
*/

/*@
    requires bounds(x) && bounds(y);
    ensures \result == xor_op(x, y);
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    //@ assert bounds(x);
    //@ assert bounds(y);
    //@ assert xor_op(x, y) == (x ^ y);
    return x ^ y;
}
