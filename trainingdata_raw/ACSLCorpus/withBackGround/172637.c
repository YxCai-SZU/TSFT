#include <stdint.h>

/*@
    predicate valid_inputs(integer a, integer b, integer h) =
        1 <= a <= 100 &&
        1 <= b <= 100 &&
        1 <= h <= 100 &&
        h % 2 == 0;

    logic integer expected_result(integer a, integer b, integer h) =
        (h * (a + b)) / 2;

    lemma bounds_lemma:
        \forall integer a, b, h;
        valid_inputs(a, b, h) ==>
        2 <= a + b <= 200 &&
        2 <= h * (a + b) <= 20000;
*/

/*@
    requires valid_inputs(a, b, h);
    ensures \result == expected_result(a, b, h);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t h)
{
    // Variable declarations at scope top
    uint32_t ans;

    //@ assert 2 <= a + b <= 200;
    //@ assert 2 <= h * (a + b) <= 20000;

    ans = (h * (a + b)) / 2;

    //@ assert ans == expected_result(a, b, h);

    return ans;
}
