#include <stddef.h>

/*@
    predicate valid_params(integer a, integer b, integer h) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= h && h <= 100 &&
        h % 2 == 0;

    logic integer expected_result(integer a, integer b, integer h) =
        (a + b) * h / 2;

    lemma sum_bounds:
        \forall integer a, b;
        valid_params(a, b, 1) ==> 1 <= a + b && a + b <= 200;

    lemma product_bounds:
        \forall integer a, b, h;
        valid_params(a, b, h) && 1 <= a + b && a + b <= 200 ==>
        1 <= (a + b) * h && (a + b) * h <= 20000;
*/

/*@
    requires valid_params(a, b, h);
    ensures \result == expected_result(a, b, h);
    assigns \nothing;
*/
size_t func(size_t a, size_t b, size_t h)
{
    // Variable declarations at scope top
    size_t result;

    //@ assert 1 <= a + b && a + b <= 200;
    //@ assert 1 <= (a + b) * h && (a + b) * h <= 20000;

    result = (a + b) * h / 2;
    return result;
}
