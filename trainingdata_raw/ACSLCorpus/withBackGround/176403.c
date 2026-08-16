#include <stdbool.h>

/*@
    predicate bounds(integer x, integer y, integer z) =
        x <= 10000 && y <= 10000 && z <= 10000 &&
        1 <= x && 1 <= y && 1 <= z;

    logic integer max_product(integer x, integer y) = x * y;

    lemma product_bound:
        \forall integer x, y;
        bounds(x, y, 10000) ==> max_product(x, y) <= 10000 * 10000;
*/

/*@
    requires bounds(x, y, z);
    ensures \result == (x * y <= z);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y, unsigned int z)
{
    // Variable declarations at scope top
    bool result;

    //@ assert x <= 10000 && y <= 10000 && z <= 10000;
    //@ assert 1 <= x && 1 <= y && 1 <= z;
    //@ assert x * y <= 10000 * 10000;
    
    result = (x * y <= z);
    return result;
}
