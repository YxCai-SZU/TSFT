#include <stdbool.h>

/*@ predicate min_bounded(int *arr, integer len, integer val) =
      \forall integer j; 0 <= j < len ==> val <= arr[j];
*/

/*@ predicate min_exists(int *arr, integer len, integer val) =
      \exists integer j; 0 <= j < len && val == arr[j];
*/

/*@
  requires \valid(arr + (0..len-1));
  requires len > 0;
  assigns \nothing;
  ensures min_bounded(arr, len, \result);
  ensures min_exists(arr, len, \result);
*/
int find_min(int *arr, int len) {
    int min_val;
    int i;
    
    min_val = arr[0];
    i = 1;
    
    /*@
      loop invariant 1 <= i <= len;
      loop invariant min_bounded(arr, i, min_val);
      loop invariant min_exists(arr, i, min_val);
      loop assigns min_val, i;
      loop variant len - i;
    */
    while (i < len) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        i = i + 1;
    }
    
    return min_val;
}
