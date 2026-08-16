#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_array(int *arr, size_t len) =
        len > 0 && \valid(arr + (0 .. len-1));

    logic integer array_length(int *arr, size_t len) = len;

    predicate element_exists(int *arr, size_t len, integer idx, integer val) =
        0 <= idx < len && arr[idx] == val;

    predicate is_minimum(int *arr, size_t len, integer val, integer bound) =
        \forall integer k; 0 <= k < bound ==> val <= arr[k];
*/

/*@
    requires valid_array(arr, n);
    ensures \exists integer i; 0 <= i < n && \result == arr[i];
    ensures \forall integer i; 0 <= i < n ==> \result <= arr[i];
    assigns \nothing;
*/
int min_element(int *arr, size_t n)
{
    int min_val;
    size_t i;

    //@ assert n > 0;
    min_val = arr[0];
    i = 1;

    /*@
        loop invariant 1 <= i <= n;
        loop invariant \exists integer k; 0 <= k < i && min_val == arr[k];
        loop invariant \forall integer k; 0 <= k < i ==> min_val <= arr[k];
        loop invariant n > 0;
        loop assigns min_val, i;
        loop variant n - i;
    */
    while (i < n)
    {
        if (arr[i] < min_val)
        {
            min_val = arr[i];
        }
        i++;
    }

    return min_val;
}
