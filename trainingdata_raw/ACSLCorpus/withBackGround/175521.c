#include <stdint.h>

/*@
    predicate bounds(integer v) = 0 < v <= 8;

    logic integer multiply(integer a, integer b) = a * b;

    lemma product_bounds: 
        \forall integer x, y; 
        bounds(x) && bounds(y) ==> multiply(x, y) <= 64;
*/

/*@
    requires bounds(x);
    requires bounds(y);
    ensures \result == multiply(x, y);
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert bounds((integer)x);
    //@ assert bounds((integer)y);
    //@ assert multiply((integer)x, (integer)y) <= 64;

    result = x * y;
    return result;
}
