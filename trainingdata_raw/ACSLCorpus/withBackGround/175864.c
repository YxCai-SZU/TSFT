#include <stddef.h>

/*@
    predicate element_in_range(int *arr, integer len, integer idx, int val) =
        0 <= idx < len && arr[idx] == val;

    predicate all_leq(int *arr, integer len, integer bound, int val) =
        \forall integer j; 0 <= j < bound ==> arr[j] <= val;

    lemma max_exists_in_subrange:
        \forall int *arr, integer n, integer i, int max_val;
        (1 <= i <= n) &&
        element_in_range(arr, n, 0, max_val) &&
        all_leq(arr, n, i, max_val) ==>
        (\exists integer j; 0 <= j < i && arr[j] == max_val);
*/

/*@
    requires \valid(arr + (0 .. n-1));
    requires n > 0;
    assigns \nothing;
    ensures \exists integer i; 0 <= i < n && arr[i] == \result;
    ensures \forall integer i; 0 <= i < n ==> arr[i] <= \result;
*/
int max_element(int *arr, size_t n) {
    int max_val;
    size_t i;

    max_val = arr[0];
    i = 1;

    /*@
        loop invariant 1 <= i <= n;
        loop invariant \exists integer j; 0 <= j < i && arr[j] == max_val;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= max_val;
        loop invariant n > 0;
        loop assigns max_val, i;
        loop variant n - i;
    */
    while (i < n) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        i += 1;
    }
    return max_val;
}
