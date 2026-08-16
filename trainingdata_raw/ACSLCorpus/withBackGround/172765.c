#include <stddef.h>

/*@
    predicate remainder_invariant(integer n, integer rem) =
        1 <= n <= 10000 &&
        rem <= n &&
        rem >= 0 &&
        rem == n - 1000 * ((n - rem) / 1000);

    predicate final_invariant(integer n, integer rem) =
        1 <= n <= 10000 &&
        rem < 1000 &&
        rem == n - 1000 * ((n - rem) / 1000);

    lemma remainder_decreases:
        \forall integer n, integer rem;
        remainder_invariant(n, rem) && rem >= 1000 ==> rem - 1000 < rem;

    lemma remainder_increases:
        \forall integer n, integer rem;
        final_invariant(n, rem) && rem < 0 ==> - (rem + 1000) < -rem;
*/

/*@
    requires 1 <= n <= 10000;
    ensures \result < 1000;
    ensures \result >= 0;
    ensures \result == 1000 - n % 1000 || \result == 0;
*/
size_t func(size_t n)
{
    size_t remainder;
    size_t ans;

    remainder = n;

    /*@
        loop invariant remainder_invariant(n, remainder);
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 1000)
    {
        //@ assert remainder >= 1000;
        remainder -= 1000;
    }

    /*@
        loop invariant final_invariant(n, remainder);
        loop assigns remainder;
        loop variant -remainder;
    */
    while (remainder < 0)
    {
        //@ assert remainder < 0;
        remainder += 1000;
    }

    if (remainder > 0)
    {
        ans = 1000 - remainder;
    }
    else
    {
        ans = 0;
    }

    //@ assert ans < 1000;
    //@ assert ans >= 0;
    //@ assert ans == 1000 - n % 1000 || ans == 0;
    return ans;
}
