#include <stddef.h>

/*@
  requires \valid_read(arr + (0 .. len-1));
  requires len > 0;
  assigns \nothing;
  ensures \exists integer i; 0 <= i < len && \result == arr[i];
  ensures \forall integer j; 0 <= j < len ==> \result >= arr[j];
*/
int max_in_list(int* arr, size_t len) {
    //@ assert len > 0;
    
    int max_value;
    size_t i;
    
    max_value = arr[0];
    i = 1;
    
    /*@
      loop invariant 1 <= i <= len;
      loop invariant \exists integer k; 0 <= k < i && max_value == arr[k];
      loop invariant \forall integer j; 0 <= j < i ==> max_value >= arr[j];
      loop assigns max_value, i;
      loop variant len - i;
    */
    while (i < len) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
        i++;
    }
    
    //@ assert \exists integer k; 0 <= k < len && max_value == arr[k];
    //@ assert \forall integer j; 0 <= j < len ==> max_value >= arr[j];
    
    return max_value;
}
