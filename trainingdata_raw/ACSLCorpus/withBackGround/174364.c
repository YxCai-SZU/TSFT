#include <stdint.h>

/*@
    predicate in_range(integer v) = 1 <= v && v <= 100;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bound: \forall integer x, y; in_range(x) && in_range(y) ==> product(x, y) <= 100 * 100;
    lemma result_property: \forall integer x, y, r; in_range(x) && in_range(y) && r <= product(x, y) && (r == product(x, y) - 1 || r == product(x, y)) ==> r <= product(x, y);
*/

/*@
    requires in_range(x);
    requires in_range(y);
    ensures \result <= product(x, y);
    ensures \result == product(x, y) - 1 || \result == product(x, y);
*/
uint32_t func(uint32_t x, uint32_t y)
{
    // Variable declarations
    uint32_t result;

    //@ assert in_range(x);
    //@ assert in_range(y);
    //@ assert product(x, y) <= 100 * 100;

    if (x * y > 0)
    {
        result = x * y - 1;
    }
    else
    {
        result = 0;
    }

    //@ assert result <= product(x, y);
    //@ assert result == product(x, y) - 1 || result == product(x, y);

    return result;
}
