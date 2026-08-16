#include <stddef.h>
#include <stdbool.h>

/*@
  requires min_val <= max_val;
  requires \valid(nums + (0..len-1));
  assigns \nothing;
  ensures \result <= len;
  ensures \forall integer i; 0 <= i < len ==>
            (nums[i] >= min_val && nums[i] <= max_val) ==> \result > 0;
*/
size_t count_in_range(const int* nums, size_t len, int min_val, int max_val) {
    size_t count = 0;
    size_t i = 0;

    /*@
      loop invariant 0 <= i <= len;
      loop invariant count <= i;
      loop invariant \forall integer j; 0 <= j < i ==>
                      (nums[j] >= min_val && nums[j] <= max_val) ==> count > 0;
      loop assigns i, count;
      loop variant len - i;
    */
    while (i < len) {
        int num = nums[i];
        if (num >= min_val && num <= max_val) {
            //@ assert ((num) >= (min_val) && (num) <= (max_val));
            count++;
        }
        i++;
    }
    return count;
}
