#include <stdbool.h>
#include <stddef.h>

/*@ predicate strictly_increasing(int *arr, integer len) =
      \forall integer i; 0 <= i < len - 1 ==> arr[i] < arr[i + 1];
*/

/*@
  requires 0 <= len < 0x80000000;
  requires \valid_read(arr + (0 .. len-1));
  assigns \nothing;
  ensures \result == true <==> strictly_increasing(arr, len);
*/
bool is_strictly_increasing(int *arr, size_t len) {
    if (len == 0) {
        return true;
    }
    
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len - 1;
      loop invariant \forall integer j; 0 <= j < i ==> arr[j] < arr[j + 1];
      loop assigns i;
      loop variant len - 1 - i;
    */
    while (i < len - 1) {
        //@ assert 0 <= i < len - 1;
        
        if (arr[i] >= arr[i + 1]) {
            return false;
        }
        
        i++;
    }
    
    return true;
}
