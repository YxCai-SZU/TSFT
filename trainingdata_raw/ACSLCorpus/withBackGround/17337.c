#include <stdbool.h>

/*@
    predicate is_min(integer min, int *arr, integer n, integer i) =
        \forall integer k; 0 <= k < i ==> min <= arr[k];
 */

/*@
    lemma min_initial:
        \forall int *arr, integer n;
            n > 0 ==> is_min(arr[0], arr, n, 1);
 */

/*@
    lemma min_preserved:
        \forall int *arr, integer n, integer i, integer min;
            i < n && is_min(min, arr, n, i) && arr[i] < min ==>
                is_min(arr[i], arr, n, i+1);
 */

/*@
    lemma min_not_preserved:
        \forall int *arr, integer n, integer i, integer min;
            i < n && is_min(min, arr, n, i) && arr[i] >= min ==>
                is_min(min, arr, n, i+1);
 */

/*@
    requires n > 0;
    requires \valid(arr + (0 .. n-1));
    ensures \forall integer k; 0 <= k < n ==> \result <= arr[k];
    ensures \exists integer k; 0 <= k < n && \result == arr[k];
    assigns \nothing;
 */
int min_element(int *arr, int n)
{
    int min;
    int i;
    
    min = arr[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant is_min(min, arr, n, i);
        loop invariant \exists integer k; 0 <= k < i && min == arr[k];
        loop assigns min, i;
    */
    while (i < n)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        i = i + 1;
    }
    
    return min;
}
