#include <stddef.h>
#include <stdbool.h>

/*@
    predicate valid_range(int *arr, integer len, integer m, integer n) =
        0 <= m < n < len;

    predicate count_invariant(int *arr, integer len, integer m, integer i, integer cnt) =
        m <= i <= len &&
        cnt <= i - m &&
        \forall integer k; m <= k < i ==> (arr[k] > 0 ==> cnt > 0);
*/

/*@
    requires valid_range(list1, len, m, n);
    requires \valid_read(list1 + (0 .. len-1));
    assigns \nothing;
    ensures \result <= n - m;
    ensures \forall integer k; m <= k < n ==> (list1[k] > 0 ==> \result > 0);
*/
size_t count_in_range(const int *list1, size_t len, size_t m, size_t n)
{
    size_t count = 0;
    size_t i = m;

    /*@
        loop invariant m <= i <= n;
        loop invariant count <= i - m;
        loop invariant \forall integer k; m <= k < i ==> (list1[k] > 0 ==> count > 0);
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n)
    {
        if (list1[i] > 0)
        {
            count += 1;
        }
        i += 1;
    }
    return count;
}
