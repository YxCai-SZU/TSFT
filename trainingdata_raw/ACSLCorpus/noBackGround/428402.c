#include <stddef.h>
#include <stdbool.h>

/*@
  requires \valid(nums + (0..len-1));
  requires len < 0x80000000;
  assigns \nothing;
  ensures 0 <= \result <= len;
  ensures (\forall integer i; 0 <= i < (len) ==> \at((nums)[i],Pre) == \at((nums)[i],Post));
*/
size_t count_occurrences(const int *nums, size_t len, int target) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant 0 <= count <= i;
      loop invariant (\forall integer i; 0 <= i < (len) ==> \at((nums)[i],Pre) == \at((nums)[i],Here));
      loop assigns i, count;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert (\forall integer i; 0 <= i < (len) ==> \at((nums)[i],Pre) == \at((nums)[i],Here));
        if (nums[i] == target) {
            count++;
        }
        i++;
    }
    return count;
}
