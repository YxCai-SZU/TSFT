#include <stdbool.h>

/*@ predicate contains_zero(int *nums, integer len) =
      \exists integer i; 0 <= i < len && nums[i] == 0;
*/

/*@ predicate all_positive(int *nums, integer len) =
      \forall integer i; 0 <= i < len ==> nums[i] > 0;
*/

/*@ predicate all_non_negative(int *nums, integer len) =
      \forall integer i; 0 <= i < len ==> nums[i] >= 0;
*/

/*@ predicate all_even(int *nums, integer len) =
      \forall integer i; 0 <= i < len ==> nums[i] % 2 == 0;
*/

/*@ predicate all_odd(int *nums, integer len) =
      \forall integer i; 0 <= i < len ==> nums[i] % 2 != 0;
*/

/*@
  requires -40 <= x <= 40;
  ensures \result == true <==> x >= 30;
*/
bool func(int x)
{
    bool result;
    //@ assert -40 <= x <= 40;
    
    if (x >= 30) {
        result = true;
        //@ assert x >= 30;
    } else {
        //@ assert x < 30;
        result = false;
    }
    
    return result;
}
