#include <stdint.h>

/*@
    predicate bounds(integer x, integer low, integer high) =
        low <= x && x <= high;

    logic integer product_spec(integer x, integer y) = x * y;

    lemma product_bound:
        \forall integer x, y;
            bounds(x, 0, 10) && bounds(y, 0, 10) ==> product_spec(x, y) <= 100;
*/

/*@
    requires bounds(x, 0, 10);
    requires bounds(y, 0, 10);
    ensures \result == product_spec(x, y);
    assigns \nothing;
*/
uint32_t product(uint32_t x, uint32_t y)
{
    //@ assert bounds(x, 0, 10);
    //@ assert bounds(y, 0, 10);
    //@ assert product_spec(x, y) <= 100;
    return x * y;
}

/*@
    requires bounds(side, 0, 10);
    ensures \result == product_spec(side, side);
    assigns \nothing;
*/
uint32_t area_square(uint32_t side)
{
    //@ assert bounds(side, 0, 10);
    //@ assert product_spec(side, side) <= 100;
    return side * side;
}

int main()
{
    return 0;
}
