#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(arr + (0 .. len-1));
  requires len > 0;
  assigns \nothing;
  ensures \result >= arr[0];
  ensures \exists integer i; 0 <= i < len && arr[i] <= \result;
*/
int find_max_element(int *arr, size_t len) {
    int max_element;
    size_t i;
    
    max_element = arr[0];
    i = 1;
    
    /*@
      loop invariant 1 <= i <= len;
      loop invariant max_element >= arr[0];
      loop invariant \exists integer k; 0 <= k < i && arr[k] <= max_element;
      loop assigns max_element, i;
      loop variant len - i;
    */
    while (i < len) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
        i++;
    }
    
    //@ assert max_element >= arr[0];
    //@ assert \exists integer k; 0 <= k < len && arr[k] <= max_element;
    
    return max_element;
}
