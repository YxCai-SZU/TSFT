#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer h) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= h && h <= 100 &&
        h % 2 == 0;

    logic integer trapezoid_area(integer a, integer b, integer h) =
        (a + b) * h / 2;

    lemma addition_bound: \forall integer a, b; 1 <= a <= 100 && 1 <= b <= 100 ==> a + b <= 200;
    lemma multiplication_bound: \forall integer a, b, h; 1 <= a <= 100 && 1 <= b <= 100 && 1 <= h <= 100 ==> (a + b) * h <= 20000;
    lemma division_property: \forall integer sum, area; sum >= 0 && area == sum / 2 ==> area * 2 <= sum && sum < (area + 1) * 2;
*/

/*@
    requires valid_params(a, b, h);
    ensures \result == trapezoid_area(a, b, h);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t h)
{
    // Variable declarations at scope top
    uint32_t sum;
    uint32_t area;
    uint32_t i;
    uint32_t temp_sum;

    //@ assert a + b <= 200;
    //@ assert (a + b) * h <= 20000;

    sum = (a + b) * h;

    area = 0;
    i = 0;
    temp_sum = sum;

    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant 1 <= h <= 100;
        loop invariant h % 2 == 0;
        loop invariant temp_sum + 2 * i == sum;
        loop invariant i <= sum / 2;
        loop invariant area == 0;
        loop invariant temp_sum <= sum;
        loop assigns temp_sum, i;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        i += 1;
    }
    area = i;

    //@ assert area == (a + b) * h / 2;

    return area;
}
