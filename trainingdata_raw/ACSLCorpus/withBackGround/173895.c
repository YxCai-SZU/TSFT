#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valley(int *arr, integer idx) =
      arr[idx-1] > arr[idx] && arr[idx] < arr[idx+1];
*/

/*@ lemma valley_count_bound:
      \forall int *arr, integer len, integer count;
        (len >= 3 && count >= 0 && count <= len - 2) ==>
        count <= len - 2;
*/

/*@
  requires \valid_read(nums + (0..len-1));
  requires len >= 3;
  requires len < 0x80000000;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= len - 2;
*/
int count_valleys(int *nums, size_t len) {
    int count = 0;
    size_t i = 1;
    
    /*@
      loop invariant 1 <= i <= len - 1;
      loop invariant count >= 0;
      loop invariant count <= i - 1;
      loop assigns count, i;
      loop variant len - i;
    */
    while (i < len - 1) {
        //@ assert i >= 1 && i <= len - 2;
        if (nums[i-1] > nums[i] && nums[i] < nums[i+1]) {
            //@ assert is_valley(nums, i);
            count += 1;
        }
        i += 1;
    }
    //@ assert count <= len - 2;
    return count;
}

int main() {
    return 0;
}
