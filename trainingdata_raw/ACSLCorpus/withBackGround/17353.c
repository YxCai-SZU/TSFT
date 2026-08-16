#include <stdint.h>

/*@
    predicate bounds(integer x, integer y) =
        x <= 15 && y <= 30;
*/

/*@
    lemma sum_bound:
        \forall integer x, y;
            bounds(x, y) ==> x + y <= 45;
*/

/*@
    requires bounds(x, y);
    ensures \result == 0;
*/
int check_bounds(uint32_t x, uint32_t y)
{
    //@ assert x + y <= 45;
    return 0;
}
