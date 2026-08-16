#include <stddef.h>

/*@
  requires \valid_read(arr + (0 .. len-1));
  requires len > 0;
  assigns \nothing;
  ensures \exists integer i; 0 <= i < len && \result == arr[i];
  ensures \forall integer j; 0 <= j < len ==> \result >= arr[j];
  ensures \result >= arr[0];
*/
int find_max_element(int* arr, size_t len) {
    size_t n = len;
    int max_element = arr[0];
    size_t i = 1;
    
    /*@
      loop invariant 1 <= i <= n;
      loop invariant n == len;
      loop invariant max_element >= arr[0];
      loop invariant \exists integer k; 0 <= k < i && max_element == arr[k];
      loop invariant \forall integer j; 0 <= j < i ==> max_element >= arr[j];
      loop assigns i, max_element;
      loop variant n - i;
    */
    while (i < n) {
        //@ assert \valid_read(arr + i);
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
        i++;
    }
    return max_element;
}
