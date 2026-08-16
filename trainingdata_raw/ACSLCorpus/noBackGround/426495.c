#include <stdint.h>
#include <stdbool.h>

/*@
  requires \valid(nums + (0..len-1));
  requires len < 0x80000000;
  assigns \nothing;
  ensures \result <= len;
  ensures \forall integer i; 0 <= i < len && (((nums[i]) % 2) == 0) ==> \result > 0;
*/
unsigned count_even_numbers(int32_t *nums, unsigned len) {
    unsigned count = 0;
    unsigned i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant count <= i;
      loop invariant \forall integer j; 0 <= j < i && (((nums[j]) % 2) == 0) ==> count > 0;
      loop assigns i, count;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if ((nums[i] & 1) == 0) {
            count++;
        }
        i++;
    }
    return count;
}
