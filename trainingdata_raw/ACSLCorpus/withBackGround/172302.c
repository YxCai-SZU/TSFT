/*@
    predicate is_valid_range(integer n) =
        1 <= n <= 100000;

    predicate outer_invariant(integer n, integer i, integer count) =
        is_valid_range(n) &&
        1 <= i &&
        count <= i - 1 &&
        i <= n + 1 &&
        count <= n &&
        count >= 0;

    predicate inner_invariant(integer n, integer i, integer j, integer div, integer count) =
        is_valid_range(n) &&
        1 <= j &&
        div <= j - 1 &&
        j <= n + 1 &&
        count <= n &&
        count >= 0 &&
        1 <= i <= n &&
        1 <= j <= n + 1;

    lemma product_bound:
        \forall integer i, integer j;
            (1 <= i <= 100000 && 1 <= j <= 100000) ==> i * j <= 100000 * 100000;
*/

#include <stdint.h>

/*@
    requires 1 <= n <= 100000;
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    int64_t count = 0;
    int64_t i = 1;

    /*@
        loop invariant outer_invariant(n, i, count);
        loop invariant i <= n + 1;
        loop assigns count, i;
        loop variant n - i + 1;
    */
    while (i <= n)
    {
        int64_t div = 0;
        int64_t j = 1;

        /*@
            loop invariant inner_invariant(n, i, j, div, count);
            loop assigns div, j;
            loop variant n - j + 1;
        */
        while (j <= n)
        {
            //@ assert 1 <= i <= 100000;
            //@ assert 1 <= j <= 100000;
            //@ assert i * j <= 100000 * 100000;

            if (i * j <= n)
            {
                div += 1;
            }
            j += 1;
        }

        if (div == 8)
        {
            count += 1;
        }
        i += 1;
    }

    //@ assert count <= n;
    return count;
}
