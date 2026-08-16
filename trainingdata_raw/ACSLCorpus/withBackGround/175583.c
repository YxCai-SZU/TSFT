#include <stdbool.h>

/*@
    predicate product_bound(integer x, integer y) = x * y <= 1000;
    predicate sum_bound(integer x, integer y, integer z) = x + y + z <= 1000;
*/

/*@
    requires x <= 8 && y <= 8 && z <= 1000;
    ensures \result ==> product_bound(x, y);
    ensures \result ==> sum_bound(x, y, z);
*/
bool product_and_sum_bounds(unsigned int x, unsigned int y, unsigned int z)
{
    // Variable declarations at top of scope
    bool product_bound;
    bool sum_bound;
    bool ret;

    //@ assert x * y <= 100;
    //@ assert x * y <= 1000;

    product_bound = true;
    sum_bound = (x + y + z) <= 1000;
    ret = product_bound && sum_bound;
    
    return ret;
}
