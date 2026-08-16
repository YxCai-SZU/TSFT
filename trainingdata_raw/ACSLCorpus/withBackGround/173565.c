#include <stdbool.h>

/*@ predicate sorted(int *arr, integer len) =
      \forall integer i, j; 0 <= i <= j < len ==> arr[i] <= arr[j];
*/

/*@ predicate element_bounded(int *arr, integer len, integer max) =
      \forall integer i; 0 <= i < len ==> arr[i] <= max;
*/

/*@ predicate element_exists(int *arr, integer len, integer max) =
      \exists integer i; 0 <= i < len && arr[i] == max;
*/

/*@ lemma max_invariant_maintained:
      \forall int *arr, integer len, integer i, int max;
      sorted(arr, len) &&
      0 <= i < len &&
      element_bounded(arr, i, max) &&
      element_exists(arr, i, max) ==>
      (arr[i] > max ==> element_bounded(arr, i+1, arr[i]) && element_exists(arr, i+1, arr[i])) &&
      (arr[i] <= max ==> element_bounded(arr, i+1, max) && element_exists(arr, i+1, max));
*/

/*@ requires \valid_read(arr + (0 .. len-1));
    requires len > 0;
    requires sorted(arr, len);
    ensures element_bounded(arr, len, \result);
    ensures element_exists(arr, len, \result);
    assigns \nothing;
*/
int find_max_element(int *arr, int len) {
    int max_element;
    int i;

    max_element = arr[0];
    i = 1;

    /*@ loop invariant 0 <= i <= len;
        loop invariant element_bounded(arr, i, max_element);
        loop invariant element_exists(arr, i, max_element);
        loop assigns max_element, i;
    */
    while (i < len) {
        //@ assert i < len;
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
        i = i + 1;
    }
    return max_element;
}
