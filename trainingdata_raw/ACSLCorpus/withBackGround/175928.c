#include <stddef.h>
#include <stdbool.h>

/*@
    predicate valid_range(int *list, size_t len, size_t m, size_t n) =
        m < len && n < len && m <= n;

    predicate max_in_range(int *list, size_t len, size_t m, size_t n, integer max_val) =
        \exists integer k; m <= k <= n && max_val == list[k];

    predicate max_ge_all(int *list, size_t len, size_t m, size_t n, integer max_val) =
        \forall integer i; m <= i <= n ==> max_val >= list[i];

    lemma range_initialization:
        \forall int *list, size_t len, size_t m, size_t n;
        valid_range(list, len, m, n) ==> m < len && n < len && m <= n;
*/

/*@
    requires \valid(list1 + (0 .. len-1));
    requires m < len && n < len && m <= n;
    ensures max_in_range(list1, len, m, n, \result);
    ensures max_ge_all(list1, len, m, n, \result);
    assigns \nothing;
*/
int max_range_list(int *list1, size_t len, size_t m, size_t n)
{
    // Variable declarations at scope top
    int max;
    size_t i;

    //@ assert valid_range(list1, len, m, n);
    max = list1[m];
    i = m + 1;

    /*@
        loop invariant m < len && n < len && m <= n;
        loop invariant m < i <= n + 1;
        loop invariant \forall integer k; m <= k < i ==> max >= list1[k];
        loop invariant \exists integer k; m <= k < i && max == list1[k];
        loop assigns max, i;
        loop variant n + 1 - i;
    */
    while (i <= n)
    {
        //@ assert m <= i <= n;
        if (list1[i] > max)
        {
            max = list1[i];
        }
        i++;
    }

    //@ assert max_in_range(list1, len, m, n, max);
    //@ assert max_ge_all(list1, len, m, n, max);
    return max;
}
