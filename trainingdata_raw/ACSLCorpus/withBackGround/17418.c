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
        valid_params(a, b, 1) ==> a + b >= a && a + b <= 200;

    lemma product_bound:
        \forall integer a, b, h, sum;
        valid_params(a, b, h) && sum == a + b ==> sum * h <= 200 * 100;

    lemma division_exact:
        \forall integer a, b, h, sum, prod;
        valid_params(a, b, h) && sum == a + b && prod == sum * h ==> prod / 2 == trapezoid_area(a, b, h);
*/

/*@
    requires valid_params(a, b, h);
    ensures \result == trapezoid_area(a, b, h);
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t h)
{
    uint64_t sum;
    uint64_t prod;
    uint64_t res;

    sum = a + b;
    //@ assert sum >= a;
    //@ assert sum <= 200;

    prod = sum * h;
    //@ assert prod <= 200 * 100;

    res = prod / 2;
    //@ assert res == prod / 2;

    return res;
}
