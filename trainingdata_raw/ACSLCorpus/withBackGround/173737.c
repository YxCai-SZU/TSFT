#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_range(int* arr, integer len) =
      len == 5 &&
      \forall integer i; 0 <= i < len ==> (1 <= arr[i] && arr[i] <= 5) &&
      \exists integer i; 0 <= i < len && arr[i] == 0;
*/

/*@ lemma result_in_range:
      \forall int* arr, integer len;
        is_valid_range(arr, len) ==> \exists integer i; 0 <= i < len && arr[i] == 0;
*/

/*@
  requires \valid(v + (0 .. 4));
  requires is_valid_range(v, 5);
  ensures \result >= 1 && \result <= 5;
  ensures \result > 0;
*/
int func(int v[5]) {
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= 5;
      loop invariant is_valid_range(v, 5);
      loop invariant \forall integer k; 0 <= k < index ==> v[k] != 0;
      loop assigns index;
    */
    while (index < 5) {
        //@ assert 0 <= index < 5;
        if (v[index] == 0) {
            //@ assert v[index] == 0;
            //@ assert \exists integer i; 0 <= i < 5 && v[i] == 0;
            return (int)index + 1;
        }
        //@ assert v[index] != 0;
        index++;
    }
    return -1;
}
