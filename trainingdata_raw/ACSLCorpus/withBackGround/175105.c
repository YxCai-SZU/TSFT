#include <stddef.h>
#include <stdint.h>

/*@
    predicate a_in_range(int64_t *a, integer m, integer i) =
        \forall integer k; 0 <= k < i ==> 1 <= a[k] <= m;

    predicate b_in_range(int64_t *b, integer n, integer i) =
        \forall integer k; 0 <= k < i ==> 1 <= b[k] <= n - 1;

    predicate a_not_x(int64_t *a, integer m, integer x) =
        \forall integer k; 0 <= k < m ==> a[k] != x;

    predicate b_not_x(int64_t *b, integer n, integer x) =
        \forall integer k; 0 <= k < n - 1 ==> b[k] != x;

    lemma range_preservation_a:
        \forall int64_t *a, integer m, integer x, integer i;
        a_not_x(a, m, x) && 0 <= i <= m ==> a_not_x(a, m, x);

    lemma range_preservation_b:
        \forall int64_t *b, integer n, integer x, integer i;
        b_not_x(b, n, x) && 0 <= i <= n - 1 ==> b_not_x(b, n, x);
*/

/*@
    requires
        1 <= n <= 100 && 1 <= m <= 100 &&
        1 <= x <= n - 1 &&
        \valid(a + (0 .. m-1)) && \valid(b + (0 .. n-2)) &&
        \forall integer i; 0 <= i < m ==> 1 <= a[i] <= m &&
        \forall integer i; 0 <= i < n - 1 ==> 1 <= b[i] <= n - 1 &&
        \forall integer i; 0 <= i < m ==> a[i] != x &&
        \forall integer i; 0 <= i < n - 1 ==> b[i] != x;
    ensures
        0 <= \result <= m;
*/
int64_t func(size_t n, size_t m, int64_t x, int64_t *a, int64_t *b)
{
    int64_t cnt1 = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= m;
        loop invariant 0 <= cnt1 <= i;
        loop invariant a_in_range(a, m, i);
        loop invariant a_not_x(a, m, x);
        loop assigns i, cnt1;
    */
    while (i < m)
    {
        //@ assert 0 <= i < m;
        if (a[i] > x)
        {
            cnt1 = cnt1 + 1;
        }
        i = i + 1;
    }

    int64_t cnt2 = 0;
    i = 0;

    /*@
        loop invariant 0 <= i <= n - 1;
        loop invariant 0 <= cnt2 <= i;
        loop invariant b_in_range(b, n, i);
        loop invariant b_not_x(b, n, x);
        loop assigns i, cnt2;
    */
    while (i < n - 1)
    {
        //@ assert 0 <= i < n - 1;
        if (b[i] < x)
        {
            cnt2 = cnt2 + 1;
        }
        i = i + 1;
    }

    int64_t min_val;
    if (cnt1 < cnt2)
    {
        min_val = cnt1;
    }
    else
    {
        min_val = cnt2;
    }

    //@ assert 0 <= min_val <= m;
    return min_val;
}
