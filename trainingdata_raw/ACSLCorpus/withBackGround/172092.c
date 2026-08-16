#include <stdbool.h>

/*@
    predicate is_valid_params(integer n, integer m) =
        2 <= m && m <= n && n <= 100000 && m % 2 == 0;

    lemma loop_decreases_outer: \forall integer n, integer i; 1 <= i <= n ==> n - i >= 0;
    lemma loop_decreases_inner: \forall integer i, integer j; 1 <= j <= i ==> i - j >= 0;
*/

/*@
    requires is_valid_params(n, m);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int m)
{
    unsigned int ans = 0;
    unsigned int i = 1;

    /*@
        loop invariant 1 <= i <= n + 1;
        loop invariant ans >= 0 && ans <= i - 1;
        loop invariant is_valid_params(n, m);
        loop assigns ans, i;
        loop variant n - i;
    */
    while (i <= n)
    {
        unsigned int count = 0;
        unsigned int j = 1;

        /*@
            loop invariant 1 <= j <= i + 1;
            loop invariant count >= 0 && count <= j - 1;
            loop invariant is_valid_params(n, m);
            loop assigns count, j;
            loop variant i - j;
        */
        while (j <= i)
        {
            if (i % j == 0)
            {
                count += 1;
            }
            j += 1;
        }

        if (count == m)
        {
            ans += 1;
        }
        i += 1;
    }

    //@ assert ans >= 0 && ans <= n;
    return ans;
}
