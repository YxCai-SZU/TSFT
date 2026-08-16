#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;

    logic integer calculate_result(integer r) = (2 * r * 314) / 100;

    lemma result_relation:
        \forall integer r, pi, result, ans;
            valid_range(r) && pi == 314 && result >= 0 &&
            result == 2 * r * pi - 100 * ans ==>
            ans == (2 * r * pi - result) / 100;
*/

/*@
    requires valid_range(r);
    ensures \result == calculate_result(r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t result;
    int64_t ans;

    pi = 314;
    result = 2 * r * pi;
    ans = 0;

    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314;
        loop invariant result >= 0;
        loop invariant result == 2 * r * pi - 100 * ans;
        loop invariant ans == (2 * r * pi - result) / 100;
        loop assigns result, ans;
        loop variant result;
    */
    while (result >= 100)
    {
        result -= 100;
        ans += 1;
    }

    if (result < 0)
    {
        ans -= 1;
        result += 100;
    }

    //@ assert ans == calculate_result(r);
    return ans;
}
