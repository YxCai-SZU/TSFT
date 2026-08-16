#include <stdbool.h>

/*@ predicate is_increasing(integer a, integer b, integer c) =
      a < b && b < c;
*/

/*@
  requires \valid(nums + (0..2));
  requires -100 <= nums[0] <= 100;
  requires -100 <= nums[1] <= 100;
  requires -100 <= nums[2] <= 100;
  ensures \result ==> is_increasing(nums[0], nums[1], nums[2]);
  ensures !\result ==> !is_increasing(nums[0], nums[1], nums[2]);
*/
bool is_increasing(int nums[3]) {
    int a;
    int b;
    int c;
    bool ret;
    
    a = nums[0];
    b = nums[1];
    c = nums[2];
    
    //@ assert a == nums[0];
    //@ assert b == nums[1];
    //@ assert c == nums[2];
    
    ret = a < b && b < c;
    return ret;
}
