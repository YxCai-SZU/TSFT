#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_params(integer n, int *nums) =
    n >= 1 && n <= 100 &&
    \valid(nums + (0 .. n-1)) &&
    \forall integer i; 0 <= i < n ==> nums[i] >= 1 && nums[i] <= 100;
*/

/*@ predicate loop_invariant(integer n, int *nums, integer index, integer ans, integer b) =
    0 <= index <= n &&
    0 <= ans <= index &&
    \forall integer i; 0 <= i < index ==> nums[i] >= 1 && nums[i] <= 100;
*/

/*@ lemma ans_bounds:
    \forall integer n, integer ans;
    valid_params(n, (int *)0) && 0 <= ans <= n ==> ans >= 0 && ans <= n;
*/

/*@
requires valid_params(n, nums);
ensures \result >= 0 && \result <= n;
*/
int func(int n, int *nums)
{
    int ans = 0;
    int b = 0;
    size_t index = 0;
    
    //@ ghost int old_n = n;
    //@ ghost int *old_nums = nums;
    
    /*@ loop invariant loop_invariant(n, nums, index, ans, b);
        loop invariant n == old_n && nums == old_nums;
        loop invariant valid_params(n, nums);
        loop assigns ans, b, index;
        loop variant n - index;
    */
    while (index < (size_t)n)
    {
        int a = nums[index];
        
        //@ assert 0 <= index < n ==> nums[index] >= 1 && nums[index] <= 100;
        
        if (b <= a)
        {
            ans += 1;
            b = a;
        }
        
        //@ assert 0 <= ans <= index + 1;
        index += 1;
    }
    
    //@ assert ans >= 0 && ans <= n;
    return ans;
}
