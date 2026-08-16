#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        1 <= a <= 2 * 100000 &&
        1 <= b <= 2 * 100000 &&
        1 <= c <= 2 * 100000 &&
        1 <= k <= a + b + c &&
        a + b >= k;

    logic integer calculate_p(integer a, integer b, integer c, integer k) =
        k <= a ? k : a;

    lemma p_bounds: \forall integer a, b, c, k;
        valid_params(a, b, c, k) ==> 0 <= calculate_p(a, b, c, k) <= a;
*/

/*@
    requires valid_params(a, b, c, k);
    ensures 0 <= \result <= a;
    ensures \result == calculate_p(a, b, c, k);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t k) {
    uint32_t p = 0;
    uint32_t i = 0;

    /*@
        loop invariant 0 <= i <= k;
        loop invariant p == (i <= a ? i : a);
        loop invariant 0 <= p <= i;
        loop invariant p <= a;
        loop invariant valid_params(a, b, c, k);
        loop assigns p, i;
        loop variant k - i;
    */
    while (i < k) {
        //@ assert i < k;
        if (i < a) {
            p = p + 1;
        }
        i = i + 1;
    }
    //@ assert p == calculate_p(a, b, c, k);
    return p;
}
