#include <stdbool.h>

/*@
    predicate is_sorted(int *arr, integer n) =
        \forall integer i, j; 0 <= i < j < n ==> arr[i] <= arr[j];

    predicate element_exists(int *arr, integer n, integer val) =
        \exists integer i; 0 <= i < n && arr[i] == val;

    predicate is_max(int *arr, integer n, integer val) =
        \forall integer k; 0 <= k < n ==> val >= arr[k];
*/

/*@
    requires n > 0;
    requires \valid(arr + (0 .. n-1));
    requires is_sorted(arr, n);
    ensures element_exists(arr, n, \result);
    ensures is_max(arr, n, \result);
*/
int find_max_element(int *arr, int n) {
    int max_element;
    int i;

    max_element = arr[0];
    i = 1;

    /*@
        loop invariant 1 <= i <= n;
        loop invariant element_exists(arr, i, max_element);
        loop invariant is_max(arr, i, max_element);
        loop assigns i, max_element;
        loop variant n - i;
    */
    while (i < n) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
        i++;
    }

    return max_element;
}
