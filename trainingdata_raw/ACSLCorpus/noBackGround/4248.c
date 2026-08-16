#include <stdint.h>

/*@
  requires \valid(nums + (0..1));
  requires ((2) == 2);
  requires (1 <= (nums[0]) <= 100) && (1 <= (nums[1]) <= 100);
  assigns \nothing;
  ensures \result == nums[0] - nums[1] + 1;
*/
int64_t func(int64_t nums[2]) {
    int64_t result;
    
    //@ assert ((2) == 2);
    //@ assert (1 <= (nums[0]) <= 100);
    //@ assert (1 <= (nums[1]) <= 100);
    
    result = nums[0] - nums[1] + 1;
    return result;
}

int main() {
    return 0;
}
