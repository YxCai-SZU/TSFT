#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b, integer h) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= h && h <= 100 &&
        h % 2 == 0;

    logic integer trapezoid_area(integer a, integer b, integer h) =
        (a + b) * h / 2;

    lemma sum_bounds:
        \forall integer a, b;
        valid_input(a, b, 1) ==> a + b <= 200;

    lemma product_bounds:
        \forall integer a, b, h;
        valid_input(a, b, h) ==> (a + b) * h <= 20000;
*/

/*@
    requires valid_input(a, b, h);
    ensures \result == trapezoid_area(a, b, h);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t h)
{
    //@ assert a + b <= 200;
    //@ assert (a + b) * h <= 20000;
    return (a + b) * h / 2;
}
