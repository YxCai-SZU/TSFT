#include <stdbool.h>

/*@
    predicate in_range(integer v) = 1 <= v <= 5;

    logic integer diff_product(integer x, integer y, integer z) =
        (y - z) * (x - z);

    lemma diff_bounds:
        \forall integer x, y, z;
            in_range(x) && in_range(y) && in_range(z) ==>
            -4 <= y - z <= 4 && -4 <= x - z <= 4;

    lemma product_bounds:
        \forall integer x, y, z;
            in_range(x) && in_range(y) && in_range(z) ==>
            -16 <= diff_product(x, y, z) <= 16;
*/

/*@
    requires in_range(x) && in_range(y) && in_range(z);
    ensures \result == (diff_product(x, y, z) < 0);
    assigns \nothing;
*/
bool func(int x, int y, int z)
{
    // Variable declarations at scope top
    int product;
    bool result;

    //@ assert in_range(x);
    //@ assert in_range(y);
    //@ assert in_range(z);

    //@ assert -4 <= y - z <= 4;
    //@ assert -4 <= x - z <= 4;
    //@ assert -16 <= (y - z) * (x - z) <= 16;

    product = (y - z) * (x - z);
    result = product < 0;
    return result;
}
