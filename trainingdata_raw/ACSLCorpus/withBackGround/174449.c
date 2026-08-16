#include <stdbool.h>
#include <stddef.h>

/*@ predicate strictly_increasing(int *arr, integer len) =
      \forall integer i; 0 <= i < len - 1 ==> arr[i] < arr[i + 1];
*/

/*@
  requires 0 <= len < 0x80000000;
  requires \valid_read(arr + (0 .. len-1));
  assigns \nothing;
  ensures \result == true <==> strictly_increasing(arr, len);
*/
bool is_strictly_increasing(int *arr, size_t len) {
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant \forall integer j; 0 <= j < i - 1 ==> arr[j] < arr[j + 1];
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        if (i > 0) {
            //@ assert 0 <= i - 1 < len;
            if (arr[i] <= arr[i - 1]) {
                return false;
            }
        }
        i++;
    }
    return true;
}
