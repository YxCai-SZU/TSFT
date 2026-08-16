#include <stdbool.h>
#include <stddef.h>

/*@ predicate all_positive(int *arr, integer len) =
      \forall integer i; 0 <= i < len ==> arr[i] > 0;
*/

/*@ predicate all_odd(int *arr, integer len) =
      \forall integer i; 0 <= i < len ==> arr[i] % 2 != 0;
*/

/*@ lemma initial_len_positive: \forall integer len; len > 0 ==> len > 0; */

/*@
  requires \valid(arr + (0 .. len-1));
  requires len > 0;
  requires all_positive(arr, len);
  ensures \result == true <==> all_odd(arr, len);
  assigns \nothing;
*/
bool func(int *arr, size_t len) {
    size_t i = 0;
    //@ ghost size_t initial_len = len;
    
    /*@
      loop invariant 0 <= i <= initial_len;
      loop invariant len == initial_len;
      loop invariant all_positive(arr, len);
      loop invariant \forall integer k; 0 <= k < i ==> arr[k] % 2 != 0;
      loop invariant len > 0;
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] % 2 == 0) {
            return false;
        }
        i++;
    }
    return true;
}
