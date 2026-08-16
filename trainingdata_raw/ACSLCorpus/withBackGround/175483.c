#include <stdbool.h>
#include <stddef.h>

/*@ predicate all_nonnegative(int *arr, integer len) =
      \forall integer i; 0 <= i < len ==> arr[i] >= 0;
*/

/*@
  requires \valid(arr + (0..len-1));
  requires len < 0x80000000;
  assigns \nothing;
  ensures \result == 1 <==> all_nonnegative(arr, len);
*/
bool no_negative_numbers(int *arr, size_t len) {
    size_t i = 0;
    /*@
      loop invariant 0 <= i <= len;
      loop invariant \forall integer j; 0 <= j < i ==> arr[j] >= 0;
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] < 0) {
            return false;
        }
        i++;
    }
    return true;
}
