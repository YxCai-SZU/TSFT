#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_params(integer n, int *nums) =
      n >= 1 &&
      \valid(nums + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> 1 <= nums[i] <= 100;
*/

/*@ predicate loop_invariant(integer n, int *nums, integer index, integer h, integer m) =
      0 <= index <= n &&
      0 <= h <= index &&
      0 <= m <= 100 &&
      valid_params(n, nums) &&
      index <= n;
*/

/*@ lemma loop_decreases: 
      \forall integer n, integer index; 
      index <= n ==> n - index >= 0;
*/

/*@ requires valid_params(n, nums);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int func(int n, int *nums) {
    int m = 0;
    int h = 0;
    size_t index = 0;
    
    /*@ loop invariant loop_invariant(n, nums, index, h, m);
        loop assigns m, h, index;
        loop variant n - index;
    */
    while ((size_t)index < (size_t)n) {
        int x = nums[index];
        
        //@ assert 1 <= x <= 100;
        
        if (x <= m) {
            h += 1;
            m = x;
        }
        
        //@ assert h <= index + 1;
        //@ assert 0 <= m <= 100;
        
        index += 1;
    }
    
    //@ assert 0 <= h <= n;
    return h;
}
