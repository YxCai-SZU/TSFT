#include <stdint.h>
#include <stdbool.h>

/*@ predicate count_in_range(integer i, integer len, integer cnt) =
      i >= 0 && i <= len && cnt >= 0 && cnt <= i;
*/

/*@
  requires \valid(nums + (0..len-1));
  requires len >= 0;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= len;
  ensures \forall integer i; 0 <= i < len ==> (nums[i] > threshold ==> \result > 0);
*/
int32_t count_exceeds_threshold(int64_t *nums, int32_t len, int64_t threshold) {
    int32_t count = 0;
    int32_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant count >= 0;
      loop invariant count <= i;
      loop invariant \forall integer j; 0 <= j < i ==> (nums[j] > threshold ==> count > 0);
      loop assigns i, count;
      loop variant len - i;
    */
    while (i < len) {
        int64_t x = nums[i];
        if (x > threshold) {
            count += 1;
        }
        i += 1;
    }
    return count;
}
