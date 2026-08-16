#include <stdbool.h>

/*@ predicate is_range_sorted(integer a, integer b, integer c) =
      a < b && b < c;
*/

/*@ logic integer func_sum(integer n) =
      (n > 0 ? 1 : 0) +
      (n > 1 ? 1 : 0) +
      (n > 2 ? 1 : 0) +
      (n > 3 ? 1 : 0) +
      (n > 4 ? 1 : 0) +
      (n > 5 ? 1 : 0) +
      (n > 6 ? 1 : 0) +
      (n > 7 ? 1 : 0) +
      (n > 8 ? 1 : 0) +
      (n > 9 ? 1 : 0);
*/

/*@ lemma func_sum_bounds: 
      \forall integer n; 1 <= n <= 9 ==> 0 <= func_sum(n) <= 10;
*/

/*@
  requires 1 <= nums[0] <= 9 && 1 <= nums[1] <= 9 && 1 <= nums[2] <= 9;
  ensures \result == (nums[0] < nums[1] && nums[1] < nums[2]);
*/
bool check_range(int nums[3])
{
    int a;
    int b;
    int c;
    bool result;
    
    a = nums[0];
    b = nums[1];
    c = nums[2];
    
    //@ assert a >= 1 && a <= 9;
    result = a < b && b < c;
    
    //@ assert result == (a < b && b < c);
    return result;
}

/*@
  requires 1 <= n <= 9;
  ensures \result >= 0 && \result <= 10;
  ensures \result == func_sum(n);
*/
int func(int n)
{
    int result;
    
    result = 0;
    
    if (n > 0) {
        result += 1;
    }
    
    if (n > 1) {
        result += 1;
    }
    
    if (n > 2) {
        result += 1;
    }
    
    if (n > 3) {
        result += 1;
    }
    
    if (n > 4) {
        result += 1;
    }
    
    if (n > 5) {
        result += 1;
    }
    
    if (n > 6) {
        result += 1;
    }
    
    if (n > 7) {
        result += 1;
    }
    
    if (n > 8) {
        result += 1;
    }
    
    if (n > 9) {
        result += 1;
    }
    
    //@ assert result == func_sum(n);
    return result;
}
