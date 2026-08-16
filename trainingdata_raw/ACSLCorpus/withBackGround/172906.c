#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;

    logic integer pi_approx = 314;

    logic integer calculate_ans(integer r) = 2 * r * pi_approx;

    lemma ans_bound: \forall integer r; valid_range(r) ==> calculate_ans(r) <= 2 * 100 * 314;

    predicate division_invariant(integer r, integer ans, integer temp, integer count) =
        valid_range(r) &&
        pi_approx == 314 &&
        ans == calculate_ans(r) &&
        temp >= 0 &&
        temp == ans - count * 100 &&
        count >= 0 &&
        count <= ans / 100;
*/

/*@
    requires 1 <= r <= 100;
    ensures \result == (2 * r * 314) / 100;
*/
int64_t func(uint64_t r)
{
    // Variable declarations
    int64_t pi_approx;
    int64_t ans;
    int64_t result;
    int64_t temp;
    int64_t divisor;
    int64_t count;

    // Initializations
    pi_approx = 314;
    //@ assert pi_approx == 314;

    //@ assert 2 * (int64_t)r * pi_approx <= 2 * 100 * 314;
    ans = 2 * (int64_t)r * pi_approx;

    result = 0;
    temp = ans;
    divisor = 100;
    count = 0;

    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 314;
        loop invariant ans == 2 * (int64_t)r * pi_approx;
        loop invariant divisor == 100;
        loop invariant temp >= 0;
        loop invariant temp == ans - count * divisor;
        loop invariant count >= 0;
        loop invariant count <= ans / divisor;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        count += 1;
    }

    result = count;

    //@ assert pi_approx == 314;
    //@ assert ans == 2 * (int64_t)r * pi_approx;
    //@ assert result * 100 + temp == ans;

    return result;
}
