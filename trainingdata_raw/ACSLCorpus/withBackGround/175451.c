#include <stdint.h>

/*@
    predicate valid_range(integer x) = 0 <= x <= 100;

    logic integer ceiling_avg(integer a, integer b) = (a + b + 1) / 2;

    lemma avg_property: \forall integer a, b; valid_range(a) && valid_range(b) ==> ceiling_avg(a, b) == (a + b + 1) / 2;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == ceiling_avg(a, b);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t sum;
    uint32_t avg;

    sum = a + b;
    avg = (sum + 1) / 2;

    //@ assert avg == (a + b + 1) / 2;

    return avg;
}
