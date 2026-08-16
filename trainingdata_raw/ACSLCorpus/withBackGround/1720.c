#include <stdbool.h>
#include <limits.h>

/*@ predicate min_exists(int *arr, integer len, integer val) =
      \exists integer i; 0 <= i < len && arr[i] == val;
*/

/*@ predicate min_le_all(int *arr, integer len, integer val) =
      \forall integer j; 0 <= j < len ==> val <= arr[j];
*/

/*@ lemma min_preservation:
      \forall int *arr, integer len, integer i, integer min_val;
      0 <= i < len &&
      min_le_all(arr, i, min_val) &&
      min_exists(arr, i, min_val) &&
      min_val <= arr[i] ==>
      min_le_all(arr, i+1, min_val) && min_exists(arr, i+1, min_val);
*/

/*@ lemma min_update:
      \forall int *arr, integer len, integer i, integer min_val;
      0 <= i < len &&
      min_le_all(arr, i, min_val) &&
      min_exists(arr, i, min_val) &&
      arr[i] < min_val ==>
      min_le_all(arr, i+1, arr[i]) && min_exists(arr, i+1, arr[i]);
*/

/*@ requires \valid_read(arr + (0 .. len-1));
    requires len > 0;
    requires \forall integer i; 0 <= i < len ==> INT_MIN <= arr[i] <= INT_MAX;
    ensures min_exists(arr, len, \result);
    ensures min_le_all(arr, len, \result);
*/
int find_min(int *arr, int len) {
    int min_val;
    int i;

    min_val = arr[0];
    i = 1;

    /*@ loop invariant 1 <= i <= len;
        loop invariant min_le_all(arr, i, min_val);
        loop invariant min_exists(arr, i, min_val);
        loop assigns min_val, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert min_le_all(arr, i, min_val);
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        i = i + 1;
    }

    return min_val;
}
