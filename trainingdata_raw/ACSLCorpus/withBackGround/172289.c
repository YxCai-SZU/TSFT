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
        \forall integer a, b, h;
        valid_params(a, b, h) ==> 2 <= a + b && a + b <= 200;

    lemma product_bounds:
        \forall integer a, b, h;
        valid_params(a, b, h) && 2 <= a + b && a + b <= 200 ==>
        2 <= (a + b) * h && (a + b) * h <= 20000;
*/

/*@
    requires valid_params(a, b, h);
    ensures \result == trapezoid_area(a, b, h);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t h)
{
    // Variable declarations at scope top
    int64_t sum;
    int64_t result;
    int64_t temp_sum;
    int64_t count;

    //@ assert 2 <= a + b && a + b <= 200;
    //@ assert 2 <= (a + b) * h && (a + b) * h <= 20000;

    sum = (a + b) * h;
    result = 0;
    temp_sum = sum;
    count = 0;

    /*@
        loop invariant temp_sum + 2 * count == sum;
        loop invariant count >= 0;
        loop invariant temp_sum >= 0;
        loop invariant valid_params(a, b, h);
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        count += 1;
    }

    result = count;
    return result;
}
