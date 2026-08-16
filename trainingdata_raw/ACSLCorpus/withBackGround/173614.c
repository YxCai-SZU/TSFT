#include <stdbool.h>
#include <stddef.h>

/*@ predicate exists_valid_element(int *arr, integer len) =
      \exists integer i; 0 <= i < len && arr[i] > 20 && arr[i] < 50;
*/

/*@ predicate all_outside_range(int *arr, integer len) =
      \forall integer i; 0 <= i < len ==> arr[i] <= 20 || arr[i] >= 50;
*/

/*@ lemma loop_invariant_maintained:
      \forall int *arr, integer len, integer i;
        0 <= i <= len &&
        (\forall integer j; 0 <= j < i ==> arr[j] <= 20 || arr[j] >= 50) &&
        exists_valid_element(arr, len) ==>
        (i < len ==> exists_valid_element(arr, len));
*/

/*@
  requires \valid(arr + (0 .. len-1));
  requires exists_valid_element(arr, len);
  assigns \nothing;
  ensures \result == -1 ==> all_outside_range(arr, len);
  ensures \result != -1 ==> 
          \exists integer i; 0 <= i < len && arr[i] == \result && 
          \result > 20 && \result < 50;
*/
int find_num_greater_than_20_and_less_than_50(int *arr, size_t len) {
    size_t i = 0;
    /*@
      loop invariant 0 <= i <= len;
      loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= 20 || arr[j] >= 50;
      loop invariant exists_valid_element(arr, len);
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] > 20 && arr[i] < 50) {
            //@ assert exists_valid_element(arr, len);
            //@ assert arr[i] > 20 && arr[i] < 50;
            return arr[i];
        }
        i = i + 1;
        //@ assert 0 <= i <= len;
    }
    //@ assert all_outside_range(arr, len);
    return -1;
}
