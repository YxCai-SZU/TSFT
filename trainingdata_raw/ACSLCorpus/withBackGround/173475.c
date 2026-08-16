#include <stdint.h>

/*@
    predicate ans_upper_bound(integer n, integer ans) =
        ans <= 2 * ((n / 11) * 2) + 2;

    predicate ans_non_negative(integer ans) =
        ans >= 0;

    logic integer base_part(integer n) = (n / 11) * 2;

    lemma ans_verification:
        \forall integer n, ans;
        1 <= n <= 1000000000 ==>
        (n % 11 > 6 ==> ans == base_part(n) + 2) &&
        (n % 11 <= 6 ==> ans == base_part(n) + 1) ==>
        ans_upper_bound(n, ans) && ans_non_negative(ans);
*/

/*@
    requires 1 <= n <= 1000000000;
    ensures \result <= 2 * ((n / 11) * 2) + 2;
    ensures \result >= 0;
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    uint64_t ans;

    ans = (n / 11) * 2;

    //@ assert ans == base_part(n);

    if (n % 11 > 6)
    {
        ans = ans + 2;
        //@ assert ans == base_part(n) + 2;
    }
    else
    {
        ans = ans + 1;
        //@ assert ans == base_part(n) + 1;
    }

    //@ assert ans_upper_bound(n, ans);
    //@ assert ans_non_negative(ans);

    return ans;
}
