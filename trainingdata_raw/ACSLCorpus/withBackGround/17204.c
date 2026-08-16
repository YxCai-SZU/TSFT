#include <stdint.h>

/*@
    predicate valid_input(int64_t v0, int64_t v1, int64_t v2, int64_t v3) =
        v0 >= 1 && v0 <= 10000 &&
        v1 >= 1 && v1 <= 10000 &&
        v2 >= 1 && v2 <= 10000 &&
        v3 >= 1 && v3 <= 10000;

    logic integer product1(integer a, integer b) = a * b;
    logic integer product2(integer c, integer d) = c * d;

    lemma product_bound1:
        \forall integer a, b;
            a >= 1 && a <= 10000 && b >= 1 && b <= 10000 ==>
            product1(a, b) >= 1 && product1(a, b) <= 10000 * 10000;

    lemma product_bound2:
        \forall integer c, d;
            c >= 1 && c <= 10000 && d >= 1 && d <= 10000 ==>
            product2(c, d) >= 1 && product2(c, d) <= 10000 * 10000;
*/

/*@
    requires valid_input(v0, v1, v2, v3);
    ensures \result == product1(v0, v1) || \result == product2(v2, v3);
    ensures \result >= 1 && \result <= 10000 * 10000;
    assigns \nothing;
*/
int64_t func(int64_t v0, int64_t v1, int64_t v2, int64_t v3)
{
    int64_t ans;

    //@ assert v0 * v1 <= 10000 * 10000;
    //@ assert v2 * v3 <= 10000 * 10000;
    //@ assert v0 * v1 >= 1;
    //@ assert v2 * v3 >= 1;

    if (v0 * v1 > v2 * v3) {
        ans = v0 * v1;
    } else {
        ans = v2 * v3;
    }

    //@ assert ans == product1(v0, v1) || ans == product2(v2, v3);
    //@ assert ans >= 1 && ans <= 10000 * 10000;

    return ans;
}
