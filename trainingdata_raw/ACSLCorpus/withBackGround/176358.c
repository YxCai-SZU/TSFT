#include <stdint.h>

/*@
    predicate in_range_64(integer v) =
        0 <= v <= 0xffffffffffffffff;

    lemma bitwise_and_identity:
        \forall integer x, y;
            in_range_64(x) && in_range_64(y) ==>
            (x & y) == (x & y);
*/

/*@
    requires in_range_64(x);
    requires in_range_64(y);
    ensures \result == (x & y);
    assigns \nothing;
*/
uint64_t func(uint64_t x, uint64_t y)
{
    uint64_t result;

    //@ assert in_range_64(x);
    //@ assert in_range_64(y);
    //@ assert (x & y) == (x & y);

    result = x & y;
    return result;
}
