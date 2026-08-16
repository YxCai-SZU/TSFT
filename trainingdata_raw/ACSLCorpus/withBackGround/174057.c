#include <stdbool.h>
#include <stddef.h>

/*@ predicate exists_min(int *arr, integer len, integer min_val) =
      \exists integer idx; 0 <= idx < len && arr[idx] == min_val;
*/

/*@ predicate forall_min(int *arr, integer len, integer min_val) =
      \forall integer idx; 0 <= idx < len ==> min_val <= arr[idx];
*/

/*@ lemma min_in_range:
      \forall int *arr, integer len, integer min_val;
        len > 0 && len < 0x80000000 &&
        exists_min(arr, len, min_val) &&
        forall_min(arr, len, min_val) ==>
        \exists integer i; 0 <= i < len && min_val == arr[i];
*/

/*@
  requires \valid(arr + (0..len-1));
  requires len > 0 && len < 0x80000000;
  ensures exists_min(arr, len, \result);
  ensures forall_min(arr, len, \result);
*/
int find_min_element(int *arr, size_t len) {
    int min_element;
    size_t i;
    
    min_element = arr[0];
    i = 1;
    
    /*@
      loop invariant 1 <= i <= len;
      loop invariant exists_min(arr, i, min_element);
      loop invariant forall_min(arr, i, min_element);
      loop assigns min_element, i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] < min_element) {
            min_element = arr[i];
        }
        i++;
    }
    
    //@ assert exists_min(arr, len, min_element);
    //@ assert forall_min(arr, len, min_element);
    return min_element;
}
