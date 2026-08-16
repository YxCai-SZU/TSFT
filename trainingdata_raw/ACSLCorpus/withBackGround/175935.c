#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;

    logic integer scaled_pi = 314159;
    logic integer scaling_factor = 100000;

    logic integer expected_result(integer r) = (2 * scaled_pi * r) / scaling_factor;

    lemma division_property:
        \forall integer r, integer pi, integer scale;
        valid_range(r) && pi == scaled_pi && scale == scaling_factor ==>
        (2 * pi * r) / scale == expected_result(r);
*/

/*@
    requires valid_range(r);
    ensures \result == expected_result(r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t scale;
    int64_t ans;
    int64_t temp;
    int64_t count;

    pi = 314159;
    scale = 100000;
    ans = 0;
    temp = 2 * r * pi;
    count = 0;

    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == scaled_pi;
        loop invariant scale == scaling_factor;
        loop invariant temp >= 0;
        loop invariant temp == 2 * r * pi - count * scale;
        loop invariant count >= 0;
        loop invariant count <= 2 * scaled_pi * 100;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= scale)
    {
        temp -= scale;
        count += 1;
    }
    ans = count;

    //@ assert ans == expected_result(r);

    return ans;
}
