#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer h) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= h && h <= 100 &&
        h % 2 == 0;
*/

/*@
    lemma sum_bounds:
        \forall integer a, integer b;
        valid_params(a, b, 1) ==> 2 <= a + b && a + b <= 200;
*/

/*@
    lemma product_bounds:
        \forall integer a, integer b, integer h;
        valid_params(a, b, h) ==> 2 <= (a + b) * h && (a + b) * h <= 20000;
*/

/*@
    requires valid_params(a, b, h);
    ensures \result == (a + b) * h / 2;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t h)
{
    //@ assert 2 <= a + b && a + b <= 200;
    //@ assert 2 <= (a + b) * h && (a + b) * h <= 20000;
    return (a + b) * h / 2;
}
