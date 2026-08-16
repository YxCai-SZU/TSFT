#include <stdint.h>

/*@
    predicate bounds(integer v) = 0 <= v <= 100;

    logic integer product(integer x, integer y, integer z) = x * y * z;

    lemma product_bounds:
        \forall integer x, y, z;
            bounds(x) && bounds(y) && bounds(z) ==> 0 <= product(x, y, z) <= 1000000;
*/

/*@
    requires bounds(x) && bounds(y) && bounds(z);
    ensures \result >= 0;
    ensures \result <= x * y * z;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y, uint32_t z)
{
    //@ assert bounds(x);
    //@ assert bounds(y);
    //@ assert bounds(z);
    //@ assert x * y <= 10000;
    //@ assert x * y * z <= 1000000;
    
    uint32_t result = x * y * z;
    //@ assert result >= 0;
    //@ assert result <= x * y * z;
    return result;
}
