#include <stdbool.h>
#include <stddef.h>

/*@ predicate strictly_increasing(int *arr, integer len) =
      \forall integer i; 1 <= i < len ==> arr[i] > arr[i-1];
*/

/*@
  requires \valid_read(arr + (0 .. len-1));
  requires len < 0x80000000;
  assigns \nothing;
  ensures \result == 1 <==> strictly_increasing(arr, len);
*/
bool is_strictly_increasing(int *arr, int len) {
    if (len <= 1) {
        return true;
    }
    
    int i = 1;
    /*@
      loop invariant 1 <= i <= len;
      loop invariant \forall integer j; 1 <= j < i ==> arr[j] > arr[j-1];
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i-1 < len && 0 <= i < len;
        if (arr[i] <= arr[i - 1]) {
            return false;
        }
        i = i + 1;
    }
    return true;
}
