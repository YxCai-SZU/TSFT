#include <stdint.h>

/*@
    predicate scaled_value_invariant(integer r, integer pi_approx, integer divisor, integer scaled_value, integer temp, integer ans) =
        1 <= r <= 100 &&
        pi_approx == 314 &&
        divisor == 100 &&
        scaled_value == r * 2 * pi_approx &&
        scaled_value == (temp + ans * divisor) &&
        ans * 100 + temp == r * 2 * pi_approx &&
        0 <= ans * 100 <= r * 2 * pi_approx;

    lemma division_lemma:
        \forall integer r, integer pi_approx, integer divisor, integer scaled_value, integer temp, integer ans;
            scaled_value_invariant(r, pi_approx, divisor, scaled_value, temp, ans) && temp < divisor ==>
            ans == 2 * r * pi_approx / divisor;
*/

/*@
    requires 1 <= r <= 100;
    ensures \result == 2 * r * 314 / 100;
*/
int64_t func(int64_t r)
{
    int64_t pi_approx;
    int64_t scaled_value;
    int64_t ans;
    int64_t temp;
    int64_t divisor;

    pi_approx = 314;
    divisor = 100;
    scaled_value = r * 2 * pi_approx;
    ans = 0;
    temp = scaled_value;

    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 314;
        loop invariant divisor == 100;
        loop invariant scaled_value == r * 2 * pi_approx;
        loop invariant scaled_value == (temp + ans * divisor);
        loop invariant ans * 100 + temp == r * 2 * pi_approx;
        loop invariant 0 <= ans * 100 <= r * 2 * pi_approx;
        loop invariant temp >= 0;
        loop assigns temp, ans;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        //@ assert scaled_value == (temp + ans * divisor);
        temp -= divisor;
        ans += 1;
        //@ assert scaled_value == (temp + ans * divisor);
    }

    //@ assert ans == 2 * r * pi_approx / divisor;
    return ans;
}
