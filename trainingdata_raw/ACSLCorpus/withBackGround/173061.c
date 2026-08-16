#include <stdbool.h>

/*@ predicate is_valid_n(integer n) = 1 <= n <= 200000; */
/*@ predicate is_valid_num(integer x) = 1 <= x <= 1000000; */
/*@ predicate valid_array(integer n, int *nums) = 
      \forall integer i; 0 <= i < n ==> is_valid_num(nums[i]); */

/*@
  requires is_valid_n(n);
  requires \valid(nums + (0 .. n-1));
  requires valid_array(n, nums);
  ensures \result == (2 <= n && n <= 1000000);
*/
bool func(int n, int *nums) {
    int min;
    int i;
    
    min = 1000000;
    i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 1 <= min <= 1000000;
      loop invariant \forall integer j; 0 <= j < i ==> is_valid_num(nums[j]);
      loop invariant valid_array(n, nums);
      loop invariant is_valid_n(n);
      loop assigns i, min;
      loop variant n - i;
    */
    while (i < n) {
        int num;
        num = nums[i];
        
        //@ assert is_valid_num(num);
        
        if (num < min) {
            min = num;
        }
        
        i = i + 1;
    }
    
    return (n >= 2 && n <= 1000000);
}
