#include <stdbool.h>

/*@ predicate strictly_increasing(int *arr, integer len) =
      \forall integer i; 0 <= i < len - 1 ==> arr[i] < arr[i + 1];
*/

/*@ predicate not_strictly_increasing(int *arr, integer len) =
      \exists integer i; 0 <= i < len - 1 && arr[i] >= arr[i + 1];
*/

/*@
  requires \valid(arr + (0..len-1));
  requires len >= 1;
  assigns \nothing;
  ensures \result == true ==> strictly_increasing(arr, len);
  ensures \result == false ==> not_strictly_increasing(arr, len);
*/
bool is_strictly_increasing(int *arr, int len) {
    int i = 1;
    /*@
      loop invariant 1 <= i <= len;
      loop invariant \forall integer j; 0 <= j < i - 1 ==> arr[j] < arr[j + 1];
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i - 1 < i < len;
        if (arr[i] <= arr[i - 1]) {
            //@ assert not_strictly_increasing(arr, len);
            return false;
        }
        i = i + 1;
    }
    //@ assert strictly_increasing(arr, len);
    return true;
}
