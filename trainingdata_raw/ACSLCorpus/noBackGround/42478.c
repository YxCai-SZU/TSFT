#include <stddef.h>

/*@
  requires \valid_read(arr + (0 .. len-1));
  requires len > 0;
  assigns \nothing;
  ensures \exists integer i; 0 <= i < len && \result == arr[i];
  ensures \forall integer i; 0 <= i < len ==> arr[i] >= \result;
*/
int find_min(int* arr, size_t len) {
    int min;
    size_t i;
    
    min = arr[0];
    i = 1;
    
    /*@
      loop invariant 1 <= i <= len;
      loop invariant \exists integer k; 0 <= k < i && min == arr[k];
      loop invariant \forall integer k; 0 <= k < i ==> arr[k] >= min;
      loop invariant len > 0;
      loop assigns min, i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert \valid_read(arr + i);
        if (arr[i] < min) {
            min = arr[i];
        }
        i++;
    }
    return min;
}
