#include <stdint.h>

/*@
    predicate bounds_x(integer x) = 1 <= x <= 65535;
    predicate bounds_y(integer y) = 1 <= y <= 65535;
    logic integer product(integer x, integer y) = x * y;
    lemma product_bounds: \forall integer x, y; bounds_x(x) && bounds_y(y) ==> product(x, y) <= 65535 * 65535;
*/

/*@
    requires bounds_x(x) && bounds_y(y);
    ensures \result == product(x, y);
    assigns \nothing;
*/
uint32_t test(uint32_t x, uint32_t y)
{
    //@ assert bounds_x(x);
    //@ assert bounds_y(y);
    //@ assert product(x, y) <= 65535 * 65535;
    return x * y;
}

int main()
{
    return 0;
}
