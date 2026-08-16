#include <stddef.h>
#include <stdbool.h>

/*@ predicate element_of(integer val, int* arr, integer len) =
      \exists integer i; 0 <= i < len && arr[i] == val;
*/

/*@
  requires \valid_read(arr + (0..len-1));
  requires len > 0;
  ensures element_of(\result, arr, len);
  assigns \nothing;
*/
int find_max_in_rotated_array(int* arr, size_t len) {
    size_t low = 0;
    size_t high = len - 1;
    
    //@ ghost size_t old_low;
    //@ ghost size_t old_high;
    
    /*@
      loop invariant 0 <= low <= high < len;
      loop invariant \forall integer i; 0 <= i < len ==> element_of(arr[i], arr, len);
      loop assigns low, high, old_low, old_high;
      loop variant high - low;
    */
    while (low < high) {
        //@ ghost old_low = low;
        //@ ghost old_high = high;
        
        size_t mid = low + (high - low) / 2;
        
        //@ assert mid >= low && mid <= high;
        
        if (arr[mid] > arr[high]) {
            low = mid + 1;
            //@ assert low > old_low;
        } else {
            high = mid;
            //@ assert high < old_high;
        }
        
        //@ assert high - low < old_high - old_low;
    }
    
    //@ assert low == high;
    //@ assert element_of(arr[high], arr, len);
    return arr[high];
}
