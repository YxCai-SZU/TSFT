#include <stdint.h>

/*@
    predicate bounds(uint32_t x, uint32_t y) =
        x <= 10 && y <= 20;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bound:
        \forall integer x, y; 0 <= x <= 10 && 0 <= y <= 20 ==> product(x, y) <= 200;
*/

/*@
    requires bounds(x, y);
    ensures \result == product(x, y);
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert product(x, y) <= 200;

    result = x * y;
    return result;
}
