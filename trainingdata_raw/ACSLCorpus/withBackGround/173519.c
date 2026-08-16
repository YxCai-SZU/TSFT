#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b, integer h) =
        1 <= a <= 100 &&
        1 <= b <= 100 &&
        1 <= h <= 100 &&
        h % 2 == 0;

    logic integer trapezoid_area(integer a, integer b, integer h) =
        (a + b) * h / 2;
*/

/*@
    requires valid_input(a, b, h);
    ensures \result == trapezoid_area(a, b, h);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t h)
{
    uint32_t sum;
    uint32_t product;
    uint32_t ans;

    //@ assert 2 <= a + b <= 200;
    sum = a + b;
    //@ assert sum == a + b;

    //@ assert 2 <= sum * h <= 20000;
    product = sum * h;
    //@ assert product == sum * h;

    //@ assert product <= 20000;
    ans = product / 2;
    //@ assert ans == product / 2;

    //@ assert ans == (a + b) * h / 2;
    return ans;
}
