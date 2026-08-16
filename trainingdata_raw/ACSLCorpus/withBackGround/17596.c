#include <stdbool.h>

/*@
    predicate in_range(integer v) = 1 <= v <= 255;

    logic integer product(integer x, integer y, integer z) = x * y * z;

    lemma product_bounds:
        \forall integer x, y, z;
            in_range(x) && in_range(y) && in_range(z) ==>
            1 <= product(x, y, z) <= 255 * 255 * 255;
*/

/*@
    requires in_range(x) && in_range(y) && in_range(z);
    ensures \result == true <==> (x * y * z) % 3 == 0;
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y, unsigned int z)
{
    // Variable declarations at scope top
    bool ans;

    //@ assert 1 <= x * y <= 255 * 255;
    //@ assert 1 <= x * y * z <= 255 * 255 * 255;

    ans = (x * y * z) % 3 == 0;
    return ans;
}
