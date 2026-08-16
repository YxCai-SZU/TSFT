#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 100 <= n && n <= 999;
    predicate is_valid_ans(integer ans) =
        ans >= 111 && ans <= 999 && ans >= 100 &&
        (ans == 111 || ans == 222 || ans == 333 || ans == 444 ||
         ans == 555 || ans == 666 || ans == 777 || ans == 888 || ans == 999);
    lemma ans_bound: \forall integer ans; is_valid_ans(ans) ==> ans >= 111 && ans <= 999;
*/

/*@
    requires is_valid_n(n);
    ensures is_valid_ans(\result);
    assigns \nothing;
*/
int32_t func(uint16_t n)
{
    int32_t ans;
    uint16_t i;
    ans = 111;
    i = 1;

    /*@
        loop invariant 1 <= i <= 10;
        loop invariant is_valid_n(n);
        loop invariant is_valid_ans(ans);
        loop assigns ans, i;
        loop variant 10 - i;
    */
    while (i <= 9)
    {
        //@ assert is_valid_ans(ans);
        if (i >= n / 111)
        {
            ans = (int32_t)i * 111;
        }
        i += 1;
    }
    //@ assert is_valid_ans(ans);
    return ans;
}
