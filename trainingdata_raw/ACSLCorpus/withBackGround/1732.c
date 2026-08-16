#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b, integer h) =
        1 <= a <= 100 &&
        1 <= b <= 100 &&
        1 <= h <= 100 &&
        h % 2 == 0;

    logic integer expected_result(integer a, integer b, integer h) =
        (a + b) * h / 2;

    lemma sum_bound: \forall integer a, b; 1 <= a <= 100 && 1 <= b <= 100 ==> a + b <= 200;
    lemma product_bound: \forall integer a, b, h; 1 <= a <= 100 && 1 <= b <= 100 && 1 <= h <= 100 ==> (a + b) * h <= 200 * 100;
*/

/*@
    requires valid_input(a, b, h);
    ensures \result == expected_result(a, b, h);
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t h)
{
    // Variable declarations at scope top
    uint64_t result;

    //@ assert a + b <= 200;
    //@ assert (a + b) * h <= 200 * 100;

    result = (a + b) * h / 2;
    return result;
}
