#include <stdint.h>

/*@
    predicate is_valid_params(integer a, integer b, integer h) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= h && h <= 100 &&
        h % 2 == 0;

    logic integer trapezoid_area(integer a, integer b, integer h) = (a + b) * h / 2;

    lemma sum_bound:
        \forall integer a, b, h;
        is_valid_params(a, b, h) ==> 1 <= (a + b) * h && (a + b) * h <= 200 * 100;
*/

/*@
    requires is_valid_params(a, b, h);
    ensures \result == trapezoid_area(a, b, h);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t h)
{
    // Variable declarations at scope top
    int64_t sum;
    int64_t ans = 0;
    int64_t count = 0;
    int64_t temp_sum;

    //@ assert is_valid_params(a, b, h);
    sum = (a + b) * h;
    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant 0 <= count <= sum / 2;
        loop invariant temp_sum == sum - 2 * count;
        loop invariant h % 2 == 0;
        loop invariant 1 <= a && a <= 100;
        loop invariant 1 <= b && b <= 100;
        loop invariant 1 <= h && h <= 100;
        loop invariant ans == count;
        loop assigns temp_sum, ans, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        ans += 1;
        count += 1;
    }

    //@ assert ans == trapezoid_area(a, b, h);
    return ans;
}
