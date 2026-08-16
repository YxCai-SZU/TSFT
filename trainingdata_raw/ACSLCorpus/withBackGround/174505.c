#include <stdint.h>

/*@
    predicate valid_range(integer x) = 0 <= x <= 23;

    logic integer mod24_sum(integer a, integer b) = (a + b) % 24;

    lemma sum_range: \forall integer a, b; valid_range(a) && valid_range(b) ==> 0 <= a + b <= 46;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result <= 23;
    ensures \result == mod24_sum(a, b);
*/
uint32_t func(uint32_t a, uint32_t b) {
    // Variable declarations at scope top
    uint32_t result;

    //@ assert 0 <= a + b <= 46;

    result = (a + b) % 24;
    return result;
}
