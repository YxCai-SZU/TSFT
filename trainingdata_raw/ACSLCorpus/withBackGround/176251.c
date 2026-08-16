#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer h) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= h && h <= 100 &&
        h % 2 == 0;

    logic integer trapezoid_area(integer a, integer b, integer h) =
        (a + b) * h / 2;

    lemma sum_bounds:
        \forall integer a, b;
        valid_params(a, b, 1) ==> a + b <= 200;

    lemma product_bounds:
        \forall integer a, b, h;
        valid_params(a, b, h) ==> (a + b) * h <= 20000;
*/

/*@
    requires valid_params(a, b, h);
    ensures \result == trapezoid_area(a, b, h);
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t h)
{
    // Variable declarations at scope top
    uint64_t result;

    //@ assert a + b <= 200;
    //@ assert (a + b) * h <= 20000;
    
    result = (a + b) * h / 2;
    return result;
}
