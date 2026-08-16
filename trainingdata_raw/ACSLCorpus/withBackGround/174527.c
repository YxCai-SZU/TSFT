#include <stddef.h>
#include <stdint.h>

/*@
    predicate sorted_or_skip(int64_t *p, integer n) =
        \forall integer j; 0 <= j < n - 2 ==>
            p[j] < p[j + 1] || p[j] < p[j + 2];
 */

/*@
    requires 3 <= n <= 20;
    requires \valid(p + (0 .. n-1));
    requires sorted_or_skip(p, n);
    assigns \nothing;
    ensures 0 <= \result <= n - 2;
 */
int32_t func(size_t n, const int64_t *p)
{
    int32_t count = 0;
    size_t i = 1;
    //@ ghost size_t old_i;
    //@ ghost int32_t old_count;

    /*@
        loop invariant 1 <= i <= n - 1;
        loop invariant 0 <= count <= (int32_t)i - 1;
        loop invariant sorted_or_skip(p, n);
        loop invariant \valid(p + (0 .. n-1));
        loop assigns i, count, old_i, old_count;
        loop variant n - i;
     */
    while (i < n - 1)
    {
        //@ ghost old_i = i;
        //@ ghost old_count = count;

        //@ assert 0 <= i - 1 < n;
        if (p[i - 1] < p[i] && p[i] < p[i + 1])
        {
            count += 1;
        }
        i += 1;

        //@ assert count == old_count || count == old_count + 1;
        //@ assert i == old_i + 1;
    }
    return count;
}
