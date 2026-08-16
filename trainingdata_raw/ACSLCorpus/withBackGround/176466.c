#include <stdbool.h>
#include <stddef.h>

/*@ predicate strictly_increasing(int *arr, integer len) =
      \forall integer i; 0 <= i < len - 1 ==> arr[i] < arr[i + 1];
*/

/*@
  requires \valid_read(arr + (0 .. len-1));
  requires len < 0x80000000;
  assigns \nothing;
  ensures \result == true <==> strictly_increasing(arr, len);
*/
bool is_strictly_increasing(int *arr, size_t len) {
    int i;
    i = 0;
    /*@
      loop invariant 0 <= i <= (int)len;
      loop invariant \forall integer j; 0 <= j < i - 1 ==> arr[j] < arr[j + 1];
      loop assigns i;
      loop variant (int)len - i;
    */
    while (i < (int)len) {
        //@ assert 0 <= i && i < (int)len;
        if (i > 0 && arr[i] <= arr[i - 1]) {
            return false;
        }
        i = i + 1;
    }
    return true;
}
