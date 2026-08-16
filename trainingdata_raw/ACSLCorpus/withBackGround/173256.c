#include <stdint.h>

/*@
    predicate bounds(integer l, integer r, integer d) =
        1 <= l && l <= r && r <= 100 && 1 <= d && d <= 100;

    predicate remainder_range(integer rem, integer i) =
        0 <= rem && rem <= i;

    lemma ans_bound: \forall integer l, r, ans, i;
        l <= i && i <= r + 1 && ans <= i - l && ans >= 0 ==> ans <= r - l + 1;
*/

/*@
    requires bounds(l, r, d);
    ensures \result <= r - l + 1;
    ensures \result >= 0;
    assigns \nothing;
*/
uint64_t func(uint64_t l, uint64_t r, uint64_t d)
{
    uint64_t ans = 0;
    uint64_t i = l;

    /*@
        loop invariant l <= i && i <= r + 1;
        loop invariant ans <= i - l;
        loop invariant ans >= 0;
        loop invariant bounds(l, r, d);
        loop assigns ans, i;
        loop variant r - i + 1;
    */
    while (i <= r)
    {
        uint64_t remainder = i;

        /*@
            loop invariant remainder_range(remainder, i);
            loop invariant bounds(l, r, d);
            loop invariant l <= i && i <= r + 1;
            loop assigns remainder;
            loop variant remainder;
        */
        while (remainder >= d)
        {
            remainder -= d;
        }

        //@ assert remainder < d;
        //@ assert remainder >= 0;

        if (remainder == 0)
        {
            ans += 1;
        }

        i += 1;
    }

    //@ assert ans <= r - l + 1;
    return ans;
}
