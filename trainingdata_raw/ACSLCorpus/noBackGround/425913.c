#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(nums + (0..len-1));
  requires len > 0 && len < 0x80000000;
  ensures \exists integer i; 0 <= i < len && nums[i] == \result;
  ensures \forall integer i; 0 <= i < len ==> \result <= nums[i];
  assigns \nothing;
*/
int min_in_circular_lst(int *nums, size_t len) {
    int min_val;
    size_t i;
    
    min_val = nums[0];
    i = 1;
    
    /*@
      loop invariant 1 <= i <= len;
      loop invariant (\exists integer k; 0 <= k < (i) && (nums)[k] == (min_val));
      loop invariant (\forall integer k; 0 <= k < (i) ==> (min_val) <= (nums)[k]);
      loop assigns min_val, i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert \valid_read(nums + i);
        if (nums[i] < min_val) {
            min_val = nums[i];
        }
        i++;
    }
    
    return min_val;
}
